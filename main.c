
 /**
  * @author Nicholas Sardo <gcc.programmer@gmail.com>
  * @copyright ©2019 Nicholas Sardo
  * @license MIT
  */
 
 
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <sys/resource.h>
#include <stdlib.h>

void err_quit( char * );

int main() {
    char *login             = getlogin();
    struct passwd *p_entry  = getpwnam(login);
    struct rusage usage;

    if ( (getrusage(RUSAGE_SELF, &usage)) == -1 )
        err_quit("getrusage");

    puts(" ----- [User] ------------------");
    printf("| Login  : %20s\t|\n", getlogin());
    printf("| PWHash : %20s\t|\n", p_entry->pw_passwd);
    printf("| UName  : %20s\t|\n", p_entry->pw_name);
    printf("| UID    : %20d\t|\n", p_entry->pw_uid);
    printf("| GID    : %20d\t|\n", p_entry->pw_gid);
    printf("| PW CLS : %20s\t|\n", p_entry->pw_class);
    printf("| FULLNm : %20s\t|\n", p_entry->pw_gecos);
    printf("| HostDir: %20s\t|\n", p_entry->pw_dir);
    printf("| Shell  : %20s\t|\n", p_entry->pw_shell);
    printf("| RealUid: %20d\t|\n", getuid());
    printf("| EffUid : %20d\t|\n", geteuid());
    puts(" -------------------------------\n");
    

    puts(" ----- [Group] ----------");
    printf("| Real GId: %10d\t|\n", getgid());
    printf("| Eff  GId: %10d\t|\n", getegid());
    puts(" ------------------------\n");

    
    puts(" ----- [PIDs] -----------");
    printf("| This PID: %10d\t |\n", getpid());
    printf("| ThisPPID: %10d\t |\n", getppid());
    puts(" ------------------------\n\n");
    
    puts("| Process Resources |\n");
    printf("%15s\t%10s\t%-38s\n\n", "[STRUCT MEMBER]", "[VALUE]", "[DESCRIPTION]");
    printf("%14s\t%10ld\t%38s\n", "  ru_maxrss:",   usage.ru_maxrss,  "/*   maximum resident set size    */" );
    printf("%14s\t%10ld\t%38s\n", "  ru_maxixrss:", usage.ru_ixrss,   "/*   shared memory size           */" );
    printf("%14s\t%10ld\t%38s\n", "  ru_maxidrss:", usage.ru_idrss,   "/*   unshared data size           */" );
    printf("%14s\t%10ld\t%38s\n", "  ru_maxisrss:", usage.ru_isrss,   "/*   unshared stack size          */" );
    printf("%14s\t%10ld\t%38s\n", "  ru_minflt:",   usage.ru_minflt,  "/*   page reclaims                */" );
    printf("%14s\t%10ld\t%38s\n", "  ru_majflt:",   usage.ru_majflt,  "/*   page faults                  */" );
    printf("%14s\t%10ld\t%38s\n", "  ru_nswap:",    usage.ru_nswap,   "/*   swaps                        */" );
    printf("%14s\t%10ld\t%38s\n", "  ru_inblock:",  usage.ru_inblock, "/*   block input operations       */" );
    printf("%14s\t%10ld\t%38s\n", "  ru_oublock:",  usage.ru_oublock, "/*   block output operations      */" );
    printf("%14s\t%10ld\t%38s\n", "  ru_msgsnd:",   usage.ru_msgsnd,  "/*   messages sent                */" );
    printf("%14s\t%10ld\t%38s\n", "  ru_msgrcv:",   usage.ru_msgrcv,  "/*   messages received            */" );
    printf("%14s\t%10ld\t%38s\n", "  ru_nsignals:", usage.ru_nsignals,"/*   signals received             */" );
    printf("%14s\t%10ld\t%38s\n", "  ru_nvcsw:",    usage.ru_nvcsw,   "/*   voluntary context switches   */" );
    printf("%14s\t%10ld\t%38s\n", "  ru_nivcsw:",   usage.ru_nivcsw,  "/*   involuntary context switches */" );
    puts("\n");
    
    exit(EXIT_SUCCESS);
}

void err_quit( char *str ) {
    perror(str);
    exit(EXIT_FAILURE);
}
