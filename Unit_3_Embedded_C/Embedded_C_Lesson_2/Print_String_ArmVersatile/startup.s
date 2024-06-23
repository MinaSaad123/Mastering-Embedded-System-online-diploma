.global reset
reset:
        ldr sp, = top_stack
        bl main
stop:   
        b stop
