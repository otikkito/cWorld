#include <stdio.h>
#include <regex.h>


/* To find out more "man regcomp"
int regcomp(regex_t *restrict, const char *restrict, int);
size_t regerror(int, const regex_t *restrict, char *restrict, size_t);
int regexec(const regex_t *restrict, const char *restrict, size_t,regmatch_t [restrict], int);
void regfree(regex_t *);
*/
int main(void)
{
        regex_t reg;
        const char *regex="[abc]";
        const char *str="sadf";
        regmatch_t matches[16];

        regcomp(&reg, regex, REG_EXTENDED);

        if(regexec(&reg, str, 16, matches, 0) == 0)
        {
                printf("regex /%s/ matched string '%s' at bytes %d-%d\n",
                        regex, str, matches[0].rm_so, matches[0].rm_eo);
        }
        else
                printf("regex /%s/ does not match string '%s'\n", regex, str);
}
