def ro_to_n(ro: str) -> int:
    ro_map_n = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000,
        'IV': 4,
        'IX': 9,
        'XL': 40,
        'XC': 90,
        'CD': 400,
        'CM': 900
    }

    i = 0
    ro_last_index = len(ro)-1

    num = 0

    while i <= ro_last_index:
        if i == ro_last_index:
            c = ro[i]
            num += ro_map_n[c]
            break

        s = ro[i:i+2]
        if ro_map_n.get(s):
            num += ro_map_n[s]
            i += 1
        else:
            c = ro[i]
            num += ro_map_n[c]

        i += 1

    return num

def n_to_ro(n: int) -> str:
    n_map_ro = {
        1: {
            4: 'IV',
            5: 'V',
            9: 'IX'
        },
        2: {
            4: 'XL',
            5: 'L',
            9: 'XC'
        },
        3: {
            4: 'CD',
            5: 'D',
            9: 'CM'
        },
        4: {}
    }

    n_map_ro_first = {
        1: 'I',
        2: 'X',
        3: 'C',
        4: 'M'
    }

    ro = ''
    i = 1
    while n > 0:
        k = n % 10
        n = n // 10

        if k == 0:
            i += 1
            continue

        if n_map_ro[i].get(k):
            ro = n_map_ro[i].get(k) + ro
        elif k > 5:
            k_remains = k - 5
            ro = n_map_ro[i][5] + n_map_ro_first[i] * k_remains + ro
        else:
            ro = n_map_ro_first[i] * k + ro

        i += 1

    return ro

ro1 = input()
ro2 = input()

n1, n2 = ro_to_n(ro1), ro_to_n(ro2)
n = n1 + n2
ro = n_to_ro(n)

print(n)
print(ro)

if __name__ == '__main__':
    assert ro_to_n('DLIII') == 553
    assert ro_to_n('MCMXL') == 1940
    assert ro_to_n('I') == 1

    assert n_to_ro(553) == 'DLIII'
    assert n_to_ro(1940) == 'MCMXL'
    assert n_to_ro(1) == 'I'
    assert n_to_ro(235) == 'CCXXXV'
    assert n_to_ro(2493) == 'MMCDXCIII'