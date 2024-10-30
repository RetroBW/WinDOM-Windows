#include "\c_work\header\inigraph.h"
#include "\c_work\header\cpp.h"

InitGraph::InitGraph()
{
	// request auto detection
	gdriver = DETECT;

   /*register graphics driver*/
   errorcode = registerfarbgidriver(EGAVGA_driver_far);

	/* register driver and report any registration errors */
	if (errorcode < 0)
	{
	   printf("Graphics error: %s\n", grapherrormsg(errorcode));
	   printf("Press any key to halt:");
	   getch();
	   exit(1); /* terminate with an error code */
	}

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
	  printf("Graphics error: %s\n", grapherrormsg(errorcode));
	  printf("Press any key to halt:");
	  getch();
	  exit(1); /* terminate with an error code */
   }
}

InitGraph::~InitGraph()
{
	restorecrtmode();
	closegraph();
}

void InitGraph::RegTriplex()
{
   /*register triplex font*/
   errorcode = registerfarbgifont(triplex_font_far);

   /* register a font file and report any registration errors */
   if (errorcode < 0)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
	  exit(1); /* terminate with an error code */
   }
}

void InitGraph::RegGothic()
{
   /*register gothic font*/
   errorcode = registerfarbgifont(gothic_font_far);

   /* register a font file and report any registration errors */
   if (errorcode < 0)
   {
	  printf("Graphics error: %s\n", grapherrormsg(errorcode));
	  printf("Press any key to halt:");
	  getch();
	  exit(1); /* terminate with an error code */
   }
}

void InitGraph::RegSmall()
{
   /*register small font*/
   errorcode = registerfarbgifont(small_font_far);

   /* register a font file and report any registration errors */
   if (errorcode < 0)
   {
	  printf("Graphics error: %s\n", grapherrormsg(errorcode));
	  printf("Press any key to halt:");
	  getch();
	  exit(1); /* terminate with an error code */
   }
}

void InitGraph::RegSans()
{
   /*register sans font*/
   errorcode = registerfarbgifont(sansserif_font_far);

   /* register a font file and report any registration errors */
   if (errorcode < 0)
   {
	  printf("Graphics error: %s\n", grapherrormsg(errorcode));
	  printf("Press any key to halt:");
	  getch();
	  exit(1); /* terminate with an error code */
   }
}
