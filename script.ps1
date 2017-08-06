(Get-Date).ToString('dd.MM.yyyy   HH:mm')  | Out-File c:\Users\miner\Desktop\reboot.txt  -append

while($TRUE){
Start-Sleep -s 3
$port= new-Object System.IO.Ports.SerialPort COM3,9600,None,8,one
$port.open()
$port.WriteLine("H")
$port.Close()
}