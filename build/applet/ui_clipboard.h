#include <kdialog.h>
#include <klocale.h>

/********************************************************************************
** Form generated from reading UI file 'clipboard.ui'
**
** Created by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIPBOARD_H
#define UI_CLIPBOARD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "FormatLineEdit.h"

QT_BEGIN_NAMESPACE

class Ui_clipboard
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *tableLayout;
    QTableWidget *clipboardActionsTable;
    QVBoxLayout *buttonsLayout;
    QPushButton *addButton;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *moveButtonsLayout;
    QToolButton *moveUpButton;
    QToolButton *moveDownButton;
    QHBoxLayout *fastCopyLayout;
    QLabel *fastCopyFormatLabel;
    AdjustableClock::FormatLineEdit *fastCopyFormatEdit;

    void setupUi(QWidget *clipboard)
    {
        if (clipboard->objectName().isEmpty())
            clipboard->setObjectName(QString::fromUtf8("clipboard"));
        clipboard->resize(346, 235);
        verticalLayout = new QVBoxLayout(clipboard);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableLayout = new QHBoxLayout();
        tableLayout->setObjectName(QString::fromUtf8("tableLayout"));
        clipboardActionsTable = new QTableWidget(clipboard);
        if (clipboardActionsTable->columnCount() < 2)
            clipboardActionsTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        clipboardActionsTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        clipboardActionsTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        clipboardActionsTable->setObjectName(QString::fromUtf8("clipboardActionsTable"));
        clipboardActionsTable->setAlternatingRowColors(true);
        clipboardActionsTable->setSelectionMode(QAbstractItemView::SingleSelection);
        clipboardActionsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        clipboardActionsTable->horizontalHeader()->setDefaultSectionSize(150);
        clipboardActionsTable->horizontalHeader()->setStretchLastSection(true);
        clipboardActionsTable->verticalHeader()->setVisible(false);

        tableLayout->addWidget(clipboardActionsTable);

        buttonsLayout = new QVBoxLayout();
        buttonsLayout->setObjectName(QString::fromUtf8("buttonsLayout"));
        addButton = new QPushButton(clipboard);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        buttonsLayout->addWidget(addButton);

        editButton = new QPushButton(clipboard);
        editButton->setObjectName(QString::fromUtf8("editButton"));

        buttonsLayout->addWidget(editButton);

        deleteButton = new QPushButton(clipboard);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setEnabled(true);

        buttonsLayout->addWidget(deleteButton);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        buttonsLayout->addItem(verticalSpacer);

        moveButtonsLayout = new QHBoxLayout();
        moveButtonsLayout->setObjectName(QString::fromUtf8("moveButtonsLayout"));
        moveUpButton = new QToolButton(clipboard);
        moveUpButton->setObjectName(QString::fromUtf8("moveUpButton"));
        moveUpButton->setEnabled(true);

        moveButtonsLayout->addWidget(moveUpButton);

        moveDownButton = new QToolButton(clipboard);
        moveDownButton->setObjectName(QString::fromUtf8("moveDownButton"));
        moveDownButton->setEnabled(true);

        moveButtonsLayout->addWidget(moveDownButton);


        buttonsLayout->addLayout(moveButtonsLayout);


        tableLayout->addLayout(buttonsLayout);


        verticalLayout->addLayout(tableLayout);

        fastCopyLayout = new QHBoxLayout();
        fastCopyLayout->setObjectName(QString::fromUtf8("fastCopyLayout"));
        fastCopyFormatLabel = new QLabel(clipboard);
        fastCopyFormatLabel->setObjectName(QString::fromUtf8("fastCopyFormatLabel"));
        fastCopyFormatLabel->setWordWrap(false);

        fastCopyLayout->addWidget(fastCopyFormatLabel);

        fastCopyFormatEdit = new AdjustableClock::FormatLineEdit(clipboard);
        fastCopyFormatEdit->setObjectName(QString::fromUtf8("fastCopyFormatEdit"));

        fastCopyLayout->addWidget(fastCopyFormatEdit);


        verticalLayout->addLayout(fastCopyLayout);

#ifndef UI_QT_NO_SHORTCUT
        fastCopyFormatLabel->setBuddy(fastCopyFormatEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(clipboard);

        QMetaObject::connectSlotsByName(clipboard);
    } // setupUi

    void retranslateUi(QWidget *clipboard)
    {
        clipboard->setWindowTitle(tr2i18n("Clipboard actions", 0));
        QTableWidgetItem *___qtablewidgetitem = clipboardActionsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(tr2i18n("Format", 0));
        QTableWidgetItem *___qtablewidgetitem1 = clipboardActionsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(tr2i18n("Preview", 0));
        addButton->setText(tr2i18n("Add", 0));
        editButton->setText(tr2i18n("Edit", 0));
        deleteButton->setText(tr2i18n("Delete", 0));
#ifndef UI_QT_NO_TOOLTIP
        moveUpButton->setToolTip(tr2i18n("Move Up", 0));
#endif // QT_NO_TOOLTIP
        moveUpButton->setText(QString());
#ifndef UI_QT_NO_TOOLTIP
        moveDownButton->setToolTip(tr2i18n("Move Down", 0));
#endif // QT_NO_TOOLTIP
        moveDownButton->setText(QString());
        fastCopyFormatLabel->setText(tr2i18n("Fast copy format:", 0));
#ifndef UI_QT_NO_TOOLTIP
        fastCopyFormatEdit->setToolTip(tr2i18n("Format of string copied to clipboard after middle clicking on the clock, or activation of the relevant keyboard shortcut.", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class clipboard: public Ui_clipboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CLIPBOARD_H

