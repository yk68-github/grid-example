/***************************************************************
 * Name:      GridApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Y ()
 * Created:   2024-05-04
 * Copyright: Y ()
 * License:
 **************************************************************/

#include "GridApp.h"

//(*AppHeaders
#include "GridMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(GridApp);

bool GridApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	GridFrame* Frame = new GridFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
