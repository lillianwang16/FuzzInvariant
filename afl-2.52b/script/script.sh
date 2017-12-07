#!/bin/sh
function fail_fast {
    if [ $? == 0 ]; then
        echo return 2
        exit 2
    fi
}

name="overflow"
afl="/vagrant/FuzzInvariant/afl-2.52b"

binary_file="$afl/$name/daikon/$name"
inputFile="$afl/$name/output/daikon_input" 
cat $inputFile
rm -r "$afl/daikon-output"
kvasir-dtrace --dtrace-append "$binary_file" "$inputFile"
java daikon.Daikon --config_option daikon.derive.Derivation.disable_derived_variables=true "$afl/daikon-output/$name.decls" "$afl/daikon-output/$name.dtrace"  > "$afl/invariants_out_new.txt"

/vagrant/FuzzInvariant/my_findDiff/findDiff/main "$afl/invariants_out_new.txt" "$afl/script/invariants_found.txt"
fail_fast
/vagrant/FuzzInvariant/my_findDiff/findDiff/main "$afl/invariants_out_new.txt" "$afl/script/invariants_found_1.txt"
fail_fast
/vagrant/FuzzInvariant/my_findDiff/findDiff/main "$afl/invariants_out_new.txt" "$afl/script/invariants_found_2.txt"
fail_fast

/vagrant/FuzzInvariant/my_findDiff/findDiff/main "$afl/invariants_out_new.txt" "$afl/invariants_out_old.txt"
diff=$?
mv "$afl/invariants_out_new.txt" "$afl/invariants_out_old.txt"
#mv isDiff.txt "$afl/script/"
echo "return $diff"
exit $diff
