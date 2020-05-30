string = input()

def is_valid_number(i, j):
    if i == j:
        return string[i] != '0'

    if string[i] == '0' or string[i] > '2':
        return False

    if string[i] == '2' and string[j] > '6':
        return False

    return True

dp = [ 0 for _ in range(len(string)) ]

for i in range(len(string)):
    if i == 0 and is_valid_number(0,0):
        dp[i] = 1
    elif i == 1:
        if is_valid_number(i,i):
            dp[i] += dp[i-1]
        if is_valid_number(i-1,i):
            dp[i] += 1
    else:
        if is_valid_number(i,i):
            dp[i] += dp[i-1]
        if is_valid_number(i-1,i):
            dp[i] += dp[i-2]


print(dp[len(string)-1] % 1000000)