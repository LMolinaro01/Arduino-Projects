import serial
import time

# Arduino -> Python
ser = serial.Serial('COM4', 9600)

while True:
    if ser.in_waiting >= 2:  # Verifica se há pelo menos 2 bytes para ler

        # Lê dois bytes da serial
        high_byte = ser.read()  # Lê o byte mais significativo
        low_byte = ser.read()
        
        # Converte os dois bytes para um inteiro (16 bits)
        valor_int = (int.from_bytes(high_byte, byteorder='big') << 8) | int.from_bytes(low_byte, byteorder='big')
                
        if valor_int >= 5: #O valor vai ser relativo por ocasião
            print("Ambiente Claro")
        else:
            print("Ambiente Escuro")

        print(f"Valor do LDR: {valor_int}\n")

# Python -> Arduino

#ser.write(b'a')  # Envia o byte 'a'
#Bytes.decode(b'a')
