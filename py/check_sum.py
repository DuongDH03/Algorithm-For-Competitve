def binary_addition(a, b):
    max_len = max(len(a), len(b))

    # Normalize lengths
    a = a.zfill(max_len)
    b = b.zfill(max_len)

    result = ''
    carry = 0
    for i in range(max_len-1, -1, -1):
        temp = carry
        temp += 1 if a[i] == '1' else 0
        temp += 1 if b[i] == '1' else 0
        result = ('1' if temp % 2 == 1 else '0') + result
        carry = 0 if temp < 2 else 1       

    if carry !=0 : result = '1' + result

    return result.zfill(max_len)

def binary_checksum(data):
    # Split data into chunks of four bits
    chunks = [data[i:i+4] for i in range(0, len(data), 4)]

    # Perform binary addition of chunks
    sum_result = '0000'
    for chunk in chunks:
        sum_result = binary_addition(sum_result, chunk)

        # If overflow occurs, wrap it around
        if len(sum_result) > 4:
            sum_result = binary_addition(sum_result[1:], '0001')

    # Compute checksum (two's complement of the sum)
    checksum = ''.join('1' if bit == '0' else '0' for bit in sum_result)
    checksum = binary_addition(checksum, '0001')

    return checksum

data = '1011010110000000'
checksum = binary_checksum(data)
print(f'The checksum for the input bitstring {data} is {checksum}.')


def check_error(data, received_checksum):
    computed_checksum = binary_checksum(data)
    return computed_checksum == received_checksum

data = '0110100010110101'
received_checksum = '0001'

if check_error(data, received_checksum):
    print('No error in the bitstring.')
else:
    print('Error in the bitstring.')
