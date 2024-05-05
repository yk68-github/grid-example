/***************************************************************
 * Name:      GridMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Y ()
 * Created:   2024-05-04
 * Copyright: Y ()
 * License:
 **************************************************************/

#include "GridMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(GridFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(GridFrame)
const long GridFrame::ID_wxOK = wxNewId();
const long GridFrame::ID_LISTBOX1 = wxNewId();
const long GridFrame::ID_COMBOBOX1 = wxNewId();
const long GridFrame::ID_RADIOBOX1 = wxNewId();
const long GridFrame::idMenuQuit = wxNewId();
const long GridFrame::idMenuAbout = wxNewId();
const long GridFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(GridFrame,wxFrame)
    //(*EventTable(GridFrame)
    //*)
END_EVENT_TABLE()

GridFrame::GridFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(GridFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    GridBagSizer1 = new wxGridBagSizer(3, 3);
    Bok = new wxButton(this, ID_wxOK, _("Ok"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_wxOK"));
    Bok->SetDefault();
    GridBagSizer1->Add(Bok, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ListBox1 = new wxListBox(this, ID_LISTBOX1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX1"));
    GridBagSizer1->Add(ListBox1, wxGBPosition(1, 0), wxDefaultSpan, wxALL|wxEXPAND, 5);
    ComboBox1 = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
    GridBagSizer1->Add(ComboBox1, wxGBPosition(1, 1), wxDefaultSpan, wxALL|wxEXPAND, 5);
    wxString __wxRadioBoxChoices_1[4] =
    {
    	_("one"),
    	_("two"),
    	_("three "),
    	_("four")
    };
    RadioBox1 = new wxRadioBox(this, ID_RADIOBOX1, _("Label"), wxDefaultPosition, wxDefaultSize, 4, __wxRadioBoxChoices_1, 1, 0, wxDefaultValidator, _T("ID_RADIOBOX1"));
    GridBagSizer1->Add(RadioBox1, wxGBPosition(2, 0), wxGBSpan(1, 2), wxALL|wxEXPAND, 5);
    GridBagSizer1->AddGrowableCol(0);
    GridBagSizer1->AddGrowableCol(1);
    GridBagSizer1->AddGrowableRow(0);
    GridBagSizer1->AddGrowableRow(2);
    SetSizer(GridBagSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    GridBagSizer1->Fit(this);
    GridBagSizer1->SetSizeHints(this);

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&GridFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&GridFrame::OnAbout);
    //*)
}

GridFrame::~GridFrame()
{
    //(*Destroy(GridFrame)
    //*)
}

void GridFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void GridFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
