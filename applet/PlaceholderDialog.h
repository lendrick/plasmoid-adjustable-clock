/***********************************************************************************
* Adjustable Clock: Plasmoid to show date and time in adjustable format.
* Copyright (C) 2008 - 2012 Michal Dutkiewicz aka Emdek <emdeck@gmail.com>
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*
***********************************************************************************/

#ifndef ADJUSTABLECLOCKPLACEHOLDERDIALOG_HEADER
#define ADJUSTABLECLOCKPLACEHOLDERDIALOG_HEADER

#include <KDialog>

#include "ui_placeholder.h"

namespace AdjustableClock
{

class PlaceholderDialog : public KDialog
{
    Q_OBJECT

    public:
        PlaceholderDialog(QWidget *parent);

    protected:
        QString placeholder();

    protected slots:
        void sendSignal();
        void updatePreview();
        void selectPlaceholder(int index);
        void selectTimezoneMode(int index);
        void setShortForm(bool shortForm);
        void setTextualForm(bool textualForm);
        void setAlternativeForm(bool alternativeForm);

    private:
        Ui::placeholder m_placeholderUi;

    signals:
        void insertPlaceholder(QString placeholder);
};

}

#endif
