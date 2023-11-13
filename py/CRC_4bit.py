def compute_crc(input_bitstring, polynomial_bitstring):
    # Append the code with zeros
    input_padded = input_bitstring + '0'*(len(polynomial_bitstring) - 1)
    input_padded = list(map(int, input_padded))

    # Convert polynomial to binary
    polynomial = list(map(int, polynomial_bitstring))

    # Perform division
    for i in range(len(input_bitstring)):
        if input_padded[i] == 1:
            for j in range(len(polynomial)):
                input_padded[i+j] = input_padded[i+j] ^ polynomial[j]

    # Return remainder
    return ''.join(map(str, input_padded[-(len(polynomial)-1):]))

input_bitstring = '1010010001'
polynomial_bitstring = '10011'  # Corresponds to polynomial x^4 + x + 1

crc_code = compute_crc(input_bitstring, polynomial_bitstring)
print(f'The CRC code for the input bitstring {input_bitstring} with the generator polynomial {polynomial_bitstring} is {crc_code}.')
