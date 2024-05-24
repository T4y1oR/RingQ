import os
import sys
import random
import subprocess
import string
import hashlib
from PIL import Image
import pywin32_system32
import time


def banner():
 print('''
           +-+ +-+ +-+ +-+ +-+ +-+
           |Q| |V| |M| |2| |5| |0|
           +-+ +-+ +-+ +-+ +-+ +-+

    Github: https://github.com/T4y1oR/RingQ
         E.g: python3 QVM250.py main.exe
''')


def creatico():

    main_folder = "main"  
    random_folder = "random"  

    file_list = os.listdir(random_folder)
    for file_name in file_list:
        os.remove(os.path.join(random_folder, file_name))

    for filename in os.listdir(main_folder):
        if filename.endswith('.ico'):
            with Image.open(os.path.join(main_folder, filename)) as image:
                try:
                    # random_width = random.randint(1, 48)
                    # random_height = random.randint(1, 48)

                    resized_image = image.resize((48, 48))

                    pixel_data = list(resized_image.getdata())
                    modified_pixel_data = [(r + random.randint(-11, 11), g + random.randint(-11, 11), b + random.randint(-11, 11), a) for (r, g, b, a) in pixel_data]
                    modified_image = Image.new(resized_image.mode, resized_image.size)
                    modified_image.putdata(modified_pixel_data)

                    new_created_date = str(random.randint(0, int(time.time())))  
                    file_stats = os.stat(os.path.join(main_folder, filename))
                    os.utime(os.path.join(main_folder, filename), (file_stats.st_atime, int(new_created_date)))

                    hash_value = hashlib.md5(str(random.random()).encode()).hexdigest()

                    new_filename = os.path.join(random_folder, f"{hash_value}.ico")
                    modified_image.save(new_filename)

                    # print(f"已处理文件: {filename} -> {new_filename}")

                except:
                    pass


def generate_random_string(length):
    letters = string.ascii_letters + string.digits  
    random_string = ''.join(random.choice(letters) for _ in range(length))
    return random_string

def set_version_info(exe_path):
    rcedit_path = "rcedit-x64.exe"
    file_description = generate_random_string(50)
    company_name = generate_random_string(50)
    legal_copyright = generate_random_string(50)
    product_name = generate_random_string(50)
    file_version = "0.0.1"
    product_version = "0.0.1"

    command = [
        rcedit_path,
        exe_path,
        "--set-version-string", "FileDescription", file_description,
        "--set-file-version", file_version,
        "--set-product-version", product_version,
        "--set-version-string", "CompanyName", company_name,
        "--set-version-string", "LegalCopyright", legal_copyright,
        "--set-version-string", "FileVersion", "3.10",
        "--set-version-string", "ProductName", product_name
    ]

    subprocess.run(command, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)


def add_random_icons(exename):
    savaname = generate_random_string(15)
    icon_folder = "random"  
    icon_files = os.listdir(icon_folder)  
    random_icofiles = random.sample(icon_files, 2)  

    randomico1 = random_icofiles[0]
    randomico2 = random_icofiles[1]

    command1 = [
        "ResourceHacker.exe",
        "-open", exename,
        "-save", "output.exe",
        "-action", "addskip",
        "-res", f"{icon_folder}/{randomico1}",
        "-mask", f"ICONGROUP,{generate_random_string(15)}"
    ]
    subprocess.run(command1, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)

    time.sleep(2)

    command2 = [
        "ResourceHacker.exe",
        "-open", "output.exe",
        "-save", f"{savaname}.exe",
        "-action", "addskip",
        "-res", f"{icon_folder}/{randomico2}",
        "-mask", f"ICONGROUP,{generate_random_string(15)}"
    ]
    subprocess.run(command2, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)


    set_version_info(f"{savaname}.exe")

    os.remove("output.exe")

    return savaname

if __name__ == '__main__':
    banner()
    try:

        exename = sys.argv[1]
        creatico()
        time.sleep(2)
        savaname = add_random_icons(exename)
        if not os.path.isfile(f"{savaname}.exe"):
            print("[-] 生成失败！ 请重新尝试~ ")
        else:
            print("[+] 伪造资源成功！")
            print('[+] Enjoy! ' + f"{savaname}.exe")

    except:
        pass