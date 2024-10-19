int main(int argc, char const *argv[])
{
    decode1(100l, 20l, 3l);
    Printf("x = %ld, y  = %ld, z = %ld"  x,y,z);
    return 0;
}



void decode1(long *px, long *py, long *pz){
    long r8, rcx, rax;

    r8 = *px;
    rcx = *py;
    rax = *pz;
    *px = r8;
    *py = rcx;
    *pz = rax;

    return;
}