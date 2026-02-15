import os

dir = "TestDir"
project_dir = os.getcwd()
path = os.path.join(project_dir, dir)
os.mkdir(path)
print("Directory '%s' created" %dir) 

