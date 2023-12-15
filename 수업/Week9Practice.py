# Week9 practice
def outer():
    def middle(k):
        def inner():
            global i
            i=4
        inner()
        return i,j,k
    i =2
    return middle(j)
i = 1
j = 3

print(outer())
print(i,j)