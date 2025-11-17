def evaluate_condition(cond, vars_map):
    ops = ["==", "!=", "<", ">"]
    for op in ops:
        if op in cond:
            left, right = cond.split(op)
            left, right = left.strip(), right.strip()
            lval = vars_map[left] if left in vars_map else int(left)
            rval = vars_map[right] if right in vars_map else int(right)
            if op == "==":
                return lval == rval
            elif op == "!=":
                return lval != rval
            elif op == "<":
                return lval < rval
            elif op == ">":
                return lval > rval
    return False


def collect_block(lines, start, stop_words):
    block = []
    depth = 0
    i = start
    while i < len(lines):
        line = lines[i].strip()
        if line.startswith("for") or line.startswith("if"):
            depth += 1
        elif line == "end":
            if depth == 0 and "end" in stop_words:
                break
            depth -= 1
        elif line in stop_words and depth == 0:
            break
        block.append(lines[i])
        i += 1
    return block, i


def run(lines, vars_map):
    output = []
    i = 0
    while i < len(lines):
        line = lines[i].strip()
        if not line:
            i += 1
            continue
        parts = line.split()
        cmd = parts[0]

        if cmd == "print":
            val = parts[1]
            output.append(str(vars_map[val] if val in vars_map else val))
            i += 1

        elif cmd == "if":
            cond = " ".join(parts[1:])
            cond_val = evaluate_condition(cond, vars_map)
            i += 1
            yes_block, i = collect_block(lines, i, ("No", "end"))
            no_block = []
            if i < len(lines) and lines[i].strip() == "No":
                no_block, i = collect_block(lines, i + 1, ("end",))
            if i < len(lines) and lines[i].strip() == "end":
                i += 1
            if cond_val:
                output += run(yes_block, vars_map.copy())
            else:
                output += run(no_block, vars_map.copy())

        elif cmd == "for":
            var, start, end = parts[1], parts[2], parts[3]
            start_val = vars_map[start] if start in vars_map else int(start)
            end_val = vars_map[end] if end in vars_map else int(end)
            block, i = collect_block(lines, i + 1, ("end",))
            if i < len(lines) and lines[i].strip() == "end":
                i += 1
            for val in range(start_val, end_val + 1):
                vars_copy = vars_map.copy()
                vars_copy[var] = val
                output += run(block, vars_copy)
        else:
            i += 1
    return output


def main():
    import sys
    lines = [line.rstrip("\n") for line in sys.stdin if line.strip()]
    vars_line = lines[-2].split()
    vals = list(map(int, lines[-1].split()))
    vars_map = dict(zip(vars_line, vals))
    futuris_code = lines[:-
    main() 

FUTURIS problem solution