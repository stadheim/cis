minutter = 2
nummer = 1


# Python3
dametoalett = True

if minutter > 2:
    herretoalett = False
else:
    if nummer == 2:
        herretoalett = False
    elif nummer == 1:
        herretoalett = True
    else:
        print("Hva driver du med...")
        
print(herretoalett)
