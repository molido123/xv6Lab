//
// Created by 华根达 on 24-12-10.
//
#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "riscv.h"
#include "spinlock.h"
#include "proc.h"
#include "syscall.h"
#include "defs.h"
#include "sysinfo.h"

uint64
sys_sysinfo(void) {
    uint64 info;// user pointer to info
    argaddr(0, &info);
    struct proc *p = myproc();
    struct sysinfo si;
    si.freemem = calculate_free_memory();
    si.nproc = get_num_proc();
    if(copyout(p->pagetable, info, (char *)&si, sizeof(si)) < 0){
        return 0xffffffffffffffff;
    }
    return 0;
}