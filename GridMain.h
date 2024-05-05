/***************************************************************
 * Name:      GridMain.h
 * Purpose:   Defines Application Frame
 * Author:    Y ()
 * Created:   2024-05-04
 * Copyright: Y ()
 * License:
 **************************************************************/

#ifndef GRIDMAIN_H
#define GRIDMAIN_H

//(*Headers(GridFrame)
#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/frame.h>
#include <wx/gbsizer.h>
#include <wx/listbox.h>
#include <wx/menu.h>
#include <wx/radiobox.h>
#include <wx/statusbr.h>
//*)

class GridFrame: public wxFrame
{
    public:

        GridFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~GridFrame();

    private:

        //(*Handlers(GridFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(GridFrame)
        static const long ID_wxOK;
        static const long ID_LISTBOX1;
        static const long ID_COMBOBOX1;
        static const long ID_RADIOBOX1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(GridFrame)
        wxButton* Bok;
        wxComboBox* ComboBox1;
        wxGridBagSizer* GridBagSizer1;
        wxListBox* ListBox1;
        wxRadioBox* RadioBox1;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // GRIDMAIN_H
