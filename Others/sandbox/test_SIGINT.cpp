#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <cstring>
#include <atomic>

std::atomic<bool> quit(false);    // signal flag

void got_signal(int)
{
    quit.store(true);
}

class Foo
{
public:
    ~Foo() { std::cout << "destructor\n"; }
};

int main(void)
{
    struct sigaction sa;
    memset( &sa, 0, sizeof(sa) );
    sa.sa_handler = got_signal;
    sigfillset(&sa.sa_mask);
    sigaction(SIGINT,&sa,NULL);

    Foo foo;    // needs destruction before exit
    while (true)
    {
        // do real work here...
        sleep(1);
        if( quit.load() ) break;    // exit normally after SIGINT
    }
    return 0;
}