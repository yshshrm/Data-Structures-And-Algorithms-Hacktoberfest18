 /*
  *  PI - program to calculate to N places                          *
  *  1st argument is the number of places desired. Space is allocated *
  *  by dynamic allocation.                                           *
  *                                                                   *
  *  Programmed by Bill Davidsen after the method of G. M. Roe,       *
  *  based on a version for "E" supplied with the "B" compiler, 1970  *
  *                                                                   *
  *  Modified by Alexander Morris, September 9, 1987 to be fully      *
  *  compatible with Borland's Turbo C                                *
  *                                                                   *
  *  Modified by Jeff Smith, June 14, 1990 to allow a file name to    *
  *  be supplied as the 2nd argument, so that the output can be       *
  *  viewed later; also, messages are output to inform the user of    *
  *  what is going on.                                                *
  *                                                                   *
  *  Modified by Mariano Egurrola, July 22, 1994 replacing dynamic    *
  *  tables by files in order to avoid memory limitations, and        *         *
  *  adding processing time report.                                   *
  */

#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <stdlib.h>
#include <dos.h>

const SIZE = sizeof(long);

long  kf, ks;
long  cnt, n, i, temp, nd;
long  col, col1;
long  loc, stor[21];
long par_shift1, par_shift2;
FILE *fp;
int   y;

FILE *mf_fp;
FILE *ms_fp;

long mf_num;
long *mf_num_ptr;

long ms_num;
long *ms_num_ptr;

struct date date_proc;
struct time time_proc;

main (int argc, char *argv[])

{

    mf_num_ptr=&mf_num;
    ms_num_ptr=&ms_num;

    col = col1;

    stor[i++] = 0;                  /* also init */

    if (argc < 2) {
	fprintf (stderr, "Format is: pi <n places>\n");
	fprintf(stderr,"Range for n is 1 to %li.\n",2147483647);
	exit(0);
    }

    if (argc == 3)
	if((fp = fopen(argv[2],"w")) == NULL) {
		fprintf(stderr,"Unable to open %s.",argv[2]);
		exit(0);
	}

    n     = atol (argv[1]);

    if(n<1|n>2147483647) {
	fprintf(stderr,"Range for n is 1 to %li.\n",2147483647);
	exit(0);
	}

    system("del MF.*");
    system("del MS.*");

    if((mf_fp=fopen("MF.DAT","w+b"))==NULL)
	return(1);

    if((ms_fp=fopen("MS.DAT","w+b"))==NULL)
	return(1);

    clrscr();
    printf("PI - Program to calculate � to n places.\n\n");

    getdate(&date_proc);
    gettime(&time_proc);

    printf("Process started : %d/%d/%d %d:%d:%d\n\n",
	date_proc.da_day, date_proc.da_mon, date_proc.da_year,
	time_proc.ti_hour,time_proc.ti_min,time_proc.ti_sec);

    if(!fp)
	printf(" 3.");

    cnt   = 0;
    kf    = 25;
    ks    = 57121L;

    mf_num = 0;
    fwrite(mf_num_ptr, SIZE, 1, mf_fp);
    ms_num = 0;
    fwrite(ms_num_ptr, SIZE, 1, ms_fp);

    mf_num = 1;
    fwrite(mf_num_ptr, SIZE, 1, mf_fp);

    for (i = 2; i <= n; i += 2) {

	mf_num = -16;
	fwrite(mf_num_ptr, SIZE, 1, mf_fp);

	mf_num = 16;
	fwrite(mf_num_ptr, SIZE, 1, mf_fp);

    }

    for (i = 1; i <= n; i += 2) {

	ms_num = -4;
	fwrite(ms_num_ptr, SIZE, 1, ms_fp);

	ms_num = 4;
	fwrite(ms_num_ptr, SIZE, 1, ms_fp);

    }


    if(fp) {
	fprintf(fp,"PI - Program to calculate � to n places.\n\n");
	fprintf(fp,
	"********************************************************************\n"
	"*  Programmed by Bill Davidsen after the method of G. M. Roe,      *\n"
	"*  based on a version for \"E\" supplied with the \"B\" compiler, 1970 *\n"
	"*                                                                  *\n"
	"*  Modified by Alexander Morris, September 9, 1987 to be fully     *\n"
	"*  compatible with Borland's Turbo C                               *\n"
	"*                                                                  *\n"
        "*  Modified by Jeff Smith, June 14, 1990 to allow a file name to   *\n"
        "*  be supplied as the 2nd argument, so that the output can be      *\n"
        "*  viewed later; also, messages are output to inform the user of   *\n"
	"*  what is going on.                                               *\n"
	"*                                                                  *\n"
	"*  Modified by Mariano Egurrola, July 22, 1994 replacing dynamic   *\n"
	"*  tables by files in order to avoid memory limitations, and       *\n"
	"*  adding processing time report.                                  *\n"
	"********************************************************************\n");
	fprintf(fp,"\nProcess started : %d/%d/%d %d:%d:%d\n",
	date_proc.da_day, date_proc.da_mon, date_proc.da_year,
	time_proc.ti_hour,time_proc.ti_min,time_proc.ti_sec);
	fprintf(fp,"\n Printing � to %ld places....\n\n",n);
	printf("   Printing � to %ld places....\n\n",n);
	y = wherey();
	fprintf(fp," 3.");
    }

    while (cnt < n) {
	if (fp) {
		gotoxy(1,y);
		printf("   Calculating position %li...",cnt+1);
	}

    for (i = 0; ++i <= n - cnt;) {
	fseek(mf_fp, (i*SIZE),0);
	fread(mf_num_ptr, SIZE, 1, mf_fp);
	mf_num *= 10;
	fseek(mf_fp, (i*SIZE),0);
	fwrite(mf_num_ptr, SIZE, 1, mf_fp);

	fseek(ms_fp, (i*SIZE),0);
	fread(ms_num_ptr, SIZE, 1, ms_fp);
	ms_num *= 10;
	fseek(ms_fp, (i*SIZE),0);
	fwrite(ms_num_ptr, SIZE, 1, ms_fp);

      }

      for (i = n - cnt + 1; --i >= 2;) {

	temp = 2 * i - 1;

	fseek(mf_fp,((i-1)*SIZE),0);
	fread(mf_num_ptr, SIZE, 1, mf_fp);
	par_shift1 = mf_num;

	fseek(mf_fp,(i*SIZE),0);
	fread(mf_num_ptr, SIZE, 1, mf_fp);
	par_shift2 = mf_num;

	shift (&par_shift1,&par_shift2, temp - 2, temp * kf);

	fseek(mf_fp,(i*SIZE),0);
	mf_num=par_shift2;
	fwrite(mf_num_ptr, SIZE, 1, mf_fp);

	fseek(mf_fp,((i-1)*SIZE),0);
	mf_num=par_shift1;
	fwrite(mf_num_ptr, SIZE, 1, mf_fp);

	fseek(ms_fp,((i-1)*SIZE),0);
	fread(ms_num_ptr, SIZE, 1, ms_fp);
	par_shift1 = ms_num;

	fseek(ms_fp,(i*SIZE),0);
	fread(ms_num_ptr, SIZE, 1, ms_fp);
	par_shift2 = ms_num;

	shift (&par_shift1,&par_shift2, temp - 2, temp * ks);

	ms_num=par_shift2;
	fseek(ms_fp,(i*SIZE),0);
	fwrite(ms_num_ptr, SIZE, 1, ms_fp);

	fseek(ms_fp,((i-1)*SIZE),0);
	ms_num=par_shift1;
	fwrite(ms_num_ptr, SIZE, 1, ms_fp);

      } nd = 0;

      fseek(mf_fp, SIZE, 0);
      fread(mf_num_ptr, SIZE, 1, mf_fp);
      par_shift2 = mf_num;

      shift (&nd, &par_shift2, 1L, 5L);

      fseek(mf_fp, SIZE, 0);
      mf_num = par_shift2;
      fwrite(mf_num_ptr, SIZE, 1, mf_fp);

      fseek(ms_fp, SIZE, 0);
      fread(ms_num_ptr, SIZE, 1, ms_fp);
      par_shift2 = ms_num;

      shift (&nd, &par_shift2, 1L, 239L);

      fseek(ms_fp, SIZE, 0);
      ms_num = par_shift2;
      fwrite(ms_num_ptr, SIZE, 1, ms_fp);

      xprint (nd);
    }

    getdate(&date_proc);
    gettime(&time_proc);

    if (fp) {
      fprintf(fp,"\n\nProcess end : %d/%d/%d %d:%d:%d\n",
      date_proc.da_day, date_proc.da_mon, date_proc.da_year,
      time_proc.ti_hour,time_proc.ti_min,time_proc.ti_sec);
      fclose(fp);
      printf("   Calculation position %li...\n",n);
      printf("   Results stored in file - %s.\n",argv[2]);
    }

    printf("\n\nProcess end : %d/%d/%d %d:%d:%d\n\n",
	date_proc.da_day, date_proc.da_mon, date_proc.da_year,
	time_proc.ti_hour,time_proc.ti_min,time_proc.ti_sec);

    fclose(mf_fp);
    fclose(ms_fp);
}

shift (l1, l2, lp, lmod)
long *l1, *l2, lp, lmod;
{
    long  k;

    k = ((*l2) > 0 ? (*l2) / lmod : -(-(*l2) / lmod) - 1);
    *l2 -= k * lmod;
    *l1 += k * lp;
    par_shift1 = *l1;
    par_shift2 = *l2;
}

yprint (m)
long  m;
{
    if (cnt < n) {
	if (++col == 6) {
	    col = 1;
	    if (++col1 == 10) {
                col1 = 0;
                if (!fp) printf ("\n%4d", m % 10);
                else fprintf (fp,"\n%4d", m % 10);
            }
	    else
                if (!fp) printf ("%2d", m % 10);
                else fprintf (fp,"%2d", m % 10);
        }
        else
	    if (!fp) printf ("%d", m);
            else fprintf (fp,"%d", m);
	cnt++;
    }
}

xprint (m)
long  m;
{
    long  i, wk, wk1;

    if (m < 8) {
	for (i = 1; i <= loc;)
	    yprint (stor[i++]);
	loc = 0;
    }
    else
    if (m > 9) {
	wk = m / 10;
	m %= 10;
	for (wk1 = loc; wk1 >= 1; wk1--) {
	    wk += stor[wk1];
	    stor[wk1] = wk % 10;
	    wk /= 10;
	}
    }
    stor[++loc] = m;
}