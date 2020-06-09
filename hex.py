
def hex_hash(hex_list):
    checksum = 0
    for el in packet:
        checksum += ord(el)
    checksum = 256 - checksum%256
    checksum_hex = hex(checksum)
    print("Контрольная сумма: ", end="")
    checksum_hex =  checksum_hex[2:]
    print(checksum_hex)
    return checksum_hex


packet = ['\x10', '\x0b','\x00','\x00','\x21','\x00','\x09','\x06','\x09','\x16','\x45','\x56','\x10','\x20','\x69','\x46', '\x08', '\x70', '\x00', '\x26' ]
hash = hex_hash(packet)

