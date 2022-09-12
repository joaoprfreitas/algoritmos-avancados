################################
# João Pedro Rodrigues Freitas #
# N USP: 11316552              #
################################

def stableMarriage(womenPreference:list, menPreference:list, n:int) -> dict:
    pairs:dict = {} # 'woman':'man'

    i = 0 # man's (i + 1)st choice
    while len(pairs) < n:
        m = menPreference.pop(0) # first man on the list
        w = womenPreference[int(m[1][i]) - 1] # man's (1 + i)st choice

        if (w[0] not in pairs): # w is free
            pairs[w[0]] = m # engage w with m
            i = 0
        else: # w is currently engaged to m'
            fiance = pairs[w[0]]

            if (w[1].index(m[0]) < w[1].index(fiance[0])): # w prefers m to m'
                pairs[w[0]] = m
                menPreference.insert(0, fiance) # m' back to the list
                i = 0
            else:
                menPreference.insert(0, m)
                i += 1 # repeat for the next man's choice

    for w in pairs: # formatting dict
        pairs[w] = pairs[w][0]

    return sorted(pairs.items(), key=lambda x:x[1]) # return an ordered list of pairs (woman, man)


def main():
    testCases = int(input())

    for i in range(testCases):
        n = int(input())

        womenPreference = []
        menPreference = []

        for j in range(n):
            name, *pref = input().split()
            womenPreference.append((name, pref))

        for j in range(n):
            name, *pref = input().split()
            menPreference.append((name, pref))

        pairs = stableMarriage(womenPreference, menPreference, n)
        
        # printing results MAN - WOMAN
        for pair in pairs:
            print(pair[1], pair[0])
            
if __name__ == '__main__':
    main()
