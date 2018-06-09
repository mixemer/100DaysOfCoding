#! python3
# renameDates.py - Renames filenames with American MM-DD-YYYY date format
# to European DD-MM-YYYY.

import shutil, os, re, random, time

os.chdir('/Users/mehmetsahin/Desktop/PythonBook/test')
print (os.getcwd())

waitTime = 0.2

for i in range(29):
    month = str(random.randint(1,29))
    day = str(random.randint(1, i+1))
    year = str(random.randint(2000,2018))
    file = open(month+'-'+day+'-'+year+'.txt','w')
    print('File ' +month+'-'+day+'-'+year+'.txt Created')
    time.sleep(waitTime)
    file.close()

# Create a regex that matches files with the American date format.
datePattern = re.compile(r'''^(.*?)      # all text before the date
                        ((\d)?\d)-      # one or two digits for the month
                        ((0|1|2|3)?\d)-  # one or two digits for the day
                        ((19|20)\d\d)    # four digits for the year
                        (.*?)$           # all text after the date
                        ''',re.VERBOSE)

# Loop over the files in the working directory.
for amerFilename in os.listdir():
    mo = datePattern.search(amerFilename)

    # Skip files without a date.
    if mo == None:
        continue

    # Get the different parts of the filename.
    beforePart = mo.group(1)
    monthPart = mo.group(2)
    dayPart = mo.group(4)
    yearPart = mo.group(6)
    afterPart = mo.group(8)


    # Form the European-style filename.
    euroFilename = beforePart + dayPart + '-' +monthPart + '-' + yearPart + afterPart
    euroFilename1 = euroFilename
    amerFilename1 = amerFilename
    # Get the full, absolute file paths.
    absWorkingDir = os.path.abspath('.')
    amerFilename = os.path.join(absWorkingDir, amerFilename)
    euroFilename = os.path.join(absWorkingDir, euroFilename)
    os.path.realpath
    # Rename the files.
    print('Renaming "%s" to "%s"...' % (amerFilename1, euroFilename1))
    shutil.move(amerFilename, euroFilename)
    time.sleep(waitTime)



for filename in os.listdir():
    os.unlink(filename)
    print ('File ' + filename + ' deleted!')
    time.sleep(waitTime)



