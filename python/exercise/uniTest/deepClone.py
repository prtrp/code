def r_max(lst):
    if len(lst) == 1:
        return lst[0]
    else:
        m = r_max(lst[1:])
        print(r_max(lst[1:]))
        if m > lst[0]:
            return m
        else:
            return lst[0]

print(r_max([1, 12, 43, 23, 12, 34, 54, 34, 43, 2]))
