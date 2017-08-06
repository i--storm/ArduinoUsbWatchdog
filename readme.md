USB Watchdog for miner based on Arduino Pro Micro

Slightly modified code, inspired by this post https://bitcointalk.org/index.php?topic=1727655.0

Usage
1. Upload scetch to Arduino Pro Micro
2. Connect Arduino to motherboard reset pin according to this scheme:
3. Modify script.ps1 to your Arduino port number
4. Modify path to script.ps1 in watchdog.bat
5. Put watchdog.bat to Control Panel -> Scheduled Tasks -> < follow the prompts> to run in on system load