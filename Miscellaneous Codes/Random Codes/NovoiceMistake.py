def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    t = int(data[0])
    cases = [int(data[i]) for i in range(1, t + 1)]
    
    results = []
    
    for n in cases:
        count = 0
        bad_pairs = []
        
        for a in range(1, 10001):
            correct_result = n * a
            
            s = str(n) * a
            for b in range(1, min(10001, a * n) + 1):
                if b >= len(s):
                    k1o0n_result = 0
                else:
                    k1o0n_result = int(s[:-b])
                
                if correct_result - b == k1o0n_result:
                    count += 1
                    bad_pairs.append((a, b))
        
        results.append((count, bad_pairs))
    
    for count, pairs in results:
        print(count)
        for a, b in pairs:
            print(a, b)

if __name__ == "__main__":
    solve()
