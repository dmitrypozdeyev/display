from serial import Serial
from serial.tools import list_ports

def get_port_list():
    ports = list_ports.comports()
    return [port[0] for port in ports]    


class Display:
    
    def __init__(self, port, boudrate, str1="                    ", str2="                    ", str3="                    ", str4="                    "):
        self.port = port
        self.serial = Serial(self.port, boudrate)
        self.strings = []
        self.strings.append(str1)
        self.strings.append(str2)
        self.strings.append(str3)
        self.strings.append(str4)
        
    def update(self):
        self.serial.write(f't{self.strings[0]}{self.strings[1]}{self.strings[2]}{self.strings[3]}'.encode())
    def set_str(self, string, line=0):
        self.strings[line] = string + " " * (20 - len(string))
    def echo(self):
        self.serial.write("e".encode())
        return self.serial.readline() == b'ok\r\n'

display=Display('/dev/ttyUSB0', 9600)


display.set_str("Hello", 0)
display.set_str("World", 1)
print(get_port_list())
input("Press Enter to continue...")
if display.echo():
    print("OK")
display.update()

