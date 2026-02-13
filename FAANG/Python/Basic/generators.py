def coroutine():
    x = yield
    print(x)

c = coroutine()
next(c)
c.send(10)
next(c)
c.send(22)