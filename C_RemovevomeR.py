import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    t = int(input_data[0])
    pointer = 1
    
    results = []
    for _ in range(t):
        if pointer >= len(input_data):
            break
        
        n = int(input_data[pointer])
        s = input_data[pointer + 1]
        pointer += 2

        is_non_decreasing = True
        is_non_increasing = True
        
        for i in range(n - 1):
            if s[i] > s[i+1]: 
                is_non_decreasing = False
            if s[i] < s[i+1]: 
                is_non_increasing = False
        
        has_zero = '0' in s
        has_one = '1' in s
        minwf = 0
        
        if (is_non_decreasing or is_non_increasing) and (has_zero and has_one):
            minwf = 2
        else:
            minwf = 1
            
        results.append(str(minwf))
    
    sys.stdout.write('\n'.join(results) + '\n')

if __name__ == '__main__':
    solve()