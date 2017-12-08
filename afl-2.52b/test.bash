function fail_fast {
    if [ $? == 0 ]; then
        echo return 2
        exit 2
    fi
}
ls
fail_fast

