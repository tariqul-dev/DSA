def fun (*args, **kwargse):
    for arg in args:
        print(arg)

    
    print()

    for key, value in kwargse.items():
        print(f"key: {key} -> value: {value}")


fun("hello", "world", greeting = "Hi", message = "there")