/*
    Copyright �1994-1996, Juri Munkki
    All rights reserved.
*/

#include <CDirectObject.h>

#define	kMaxTabCardCount	32

class	CTabCards : public CDirectObject
{
public:
	WindowPtr			itsWindow;
	Rect				area;
	short				listNumber;
	short				listSize;
	Point				slant;
	short				baseLine;
	short				extraWidth;
	
	short				activeTab;
	
	short				listTabs[kMaxTabCardCount+1];
	
	short				foreInd;
	short				backInd;
	short				fontNumber;
	short				fontSize;
	
	virtual	void		ITabCards(WindowPtr	aWindow,
									short resId,
									Rect *tabRect, 
									short fFont,
									short tSize,
									short foreIndex,
									short backIndex);
	virtual	void		Draw();
	virtual	void		SelectTab(short index);
	virtual	Boolean		CheckClick(Point where, short index);
	virtual	short		Click(EventRecord *theEvent, Point where);
};