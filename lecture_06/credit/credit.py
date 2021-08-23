import cs50

def identify(ccn):

    l = len(ccn)
    if l == 15:
        if ccn[:2] == '34' or ccn[:2] == '37':
            return 'AMEX'
    elif l == 16:
        if 50 < int(ccn[:2]) < 56:
            return 'MASTERCARD'
    if l == 13 or l == 16:
        if ccn[0] == '4':
            return 'VISA'
    return 'INVALID'


def calc_l1(l1):
    """Make operations to odd digits."""
    l1_2 = [int(i) * 2 for i in l1]
    l1_2_str = ''
    for i in l1_2:
        l1_2_str += str(i)
    return sum([int(i) for i in l1_2_str])

def calc_l2(l1, l2):
    """Calculate operations to even digits."""
    res_l1 = calc_l1(l1)
    res_l2 = sum([int(i) for i in l2])
    return res_l1 + res_l2

def valid(ccn):
    """Check if credit card number is valid."""
    # Separate ccn into 2 arrays.
    l1 = [int(ccn[i]) for i in range(len(ccn) - 2, -1, -2)]
    l2 = [int(ccn[i]) for i in range(len(ccn) - 1, -1, -2)]

    # Obtain number, check if multiple of 10.
    n = calc_l2(l1, l2)
    if n % 10 == 0:
        return True
    return False

def main():
    ccn = cs50.get_string('Number: ')
    #ccn = "378282246310005"
    #ccn = "4003600000000014"
    if valid(ccn):
        print(identify(ccn))
    else:
        print("INVALID")

if __name__ == '__main__':
    main()
