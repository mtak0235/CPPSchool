import subprocess

for i in range(3000, 10000, 100):
    output = subprocess.check_output(f"time ./page.out {i}", shell=True,)
    data = output.decode('cp949')
    lines = data.splitlines()
    print(lines)
    print(">" * 10, i)
    
# 3200