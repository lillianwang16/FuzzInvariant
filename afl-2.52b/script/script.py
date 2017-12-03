#!python
import subprocess

def shell(command):
    #print "run command {}".format(command)
    try:
        output = subprocess.check_output(command, shell=True, stderr=subprocess.STDOUT)
    except Exception, e:
        output = str(e.output)
    finished = output.split('\n')
    #for line in finished:
    #    print line
    return

name = "overflow"
afl = "/home/vagrant/FuzzInvariant/afl-2.52b"
binary_file = "{}/{}/daikon/{}".format(afl, name, name)
input = 12
#print "binary file is {}".format(binary_file)
#print "input is {}".format(input)
create_dtrace = "kvasir-dtrace --dtrace-append {} {}".format( binary_file, input)

shell(create_dtrace)
run_daikon = "java daikon.Daikon --config_option daikon.derive.Derivation.disable_derived_variables=true daikon-output/{}.decls daikon-output/{}.dtrace  > invariants_out_new.txt".format(name, name)
shell(run_daikon)
checkDiff_binary = "/home/vagrant/FuzzInvariant/my_findDiff/findDiff/main"
process = subprocess.Popen([checkDiff_binary, "invariants_out_new.txt", "invariants_out_old.txt"], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
out, err = process.communicate()
#if (out == 'True'):
#     print "TRUE";
#elif (out == 'False'):
#     print "FALSE";
#else:
#    print "Wrong output";
print out

#with open('isInteresting.txt', 'a') as the_file:
#    the_file.write(out)
shell("mv /home/vagrant/FuzzInvariant/my_findDiff/findDiff/isDiff.txt ./isDiff.txt")
clean_file = "mv invariants_out_new.txt invariants_out_old.txt"
shell(clean_file)


