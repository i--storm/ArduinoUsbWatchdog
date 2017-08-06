(Get-Date).ToString('dd.MM.yyyy   HH:mm')  | Out-File reboot.txt  -append

while($TRUE){
    Start-Sleep -s 3
    $port= new-Object System.IO.Ports.SerialPort COM52,115200,None,8,one
    $port.open()
    $port.WriteLine("H")
    $port.Close()
}