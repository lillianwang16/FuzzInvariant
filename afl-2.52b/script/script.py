
import subprocess

def shell(command):
    print "run command {}".format(command)
    try:
        output = subprocess.check_output(command, shell=True, stderr=subprocess.STDOUT)
    except Exception, e:
        output = str(e.output)
    finished = output.split('\n')
    for line in finished:
        print line
    return

name = "overflow"
afl = "/vagrant/FuzzInvariant/afl-2.52b"
binary_file = "{}/{}/daikon/{}".format(afl, name, name)


inputFile = "{}/{}/output/daikon_input".format(afl, name)

print "binary file is {}".format(binary_file)
print "input file is {}".format(inputFile)
#f = open(inputFile, "r")
#input = f.read();
#print "input is {}".format(input)
#f.close()

create_dtrace = "kvasir-dtrace --dtrace-append {} {}".format( binary_file, inputFile)

shell(create_dtrace)
run_daikon = "java daikon.Daikon --config_option daikon.derive.Derivation.disable_derived_variables=true daikon-output/{}.decls daikon-output/{}.dtrace  > invariants_out_new.txt".format(name, name)
shell(run_daikon)
checkDiff_binary = "/vagrant/FuzzInvariant/my_findDiff/findDiff/main invariants_out_new.txt invariants_out_old.txt"
shell(checkDiff_binary)
#subprocess.call(checkDiff_binary)
shell("mv /vagrant/FuzzInvariant/my_findDiff/findDiff/isDiff.txt ./isNewDiff.txt")
f = open("./isNewDiff.txt", 'r')
print f.read()
f.close()
clean_file = "mv invariants_out_new.txt invariants_out_old.txt"
#shell(clean_file)


