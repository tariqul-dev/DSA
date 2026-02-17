# from pathlib import Path
#
# p = Path('/')
#
# for subdir in p.iterdir():
#     if subdir.is_dir():
#         print(subdir)


# from pathlib import Path
#
# p = Path('/home/tariqul.exabyting_bKash.com/Documents/DSA')
# files = p.rglob("*.py")
#
# for f in files:
#     print(f)


from pathlib import Path
p = Path("/")
sp = p / 'example.txt'
print(sp)

