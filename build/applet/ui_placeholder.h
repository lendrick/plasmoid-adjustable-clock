#include <kdialog.h>
#include <klocale.h>

/********************************************************************************
** Form generated from reading UI file 'placeholder.ui'
**
** Created by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLACEHOLDER_H
#define UI_PLACEHOLDER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "kcombobox.h"

QT_BEGIN_NAMESPACE

class Ui_placeholder
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *placeholderLabel;
    KComboBox *placeholderComboBox;
    QLabel *shortFormLabel;
    QCheckBox *shortFormCheckBox;
    QLabel *leadingZerosLabel;
    QCheckBox *leadingZerosCheckBox;
    QLabel *hoursModeLabel;
    QCheckBox *hoursModeCheckBox;
    QLabel *textualFormLabel;
    QCheckBox *textualFormCheckBox;
    QLabel *possessiveFormLabel;
    QCheckBox *possessiveFormCheckBox;
    KComboBox *timezoneModeComboBox;
    QLabel *timezoneModeLabel;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *previewLabel;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *placeholder)
    {
        if (placeholder->objectName().isEmpty())
            placeholder->setObjectName(QString::fromUtf8("placeholder"));
        placeholder->resize(274, 263);
        verticalLayout = new QVBoxLayout(placeholder);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        placeholderLabel = new QLabel(placeholder);
        placeholderLabel->setObjectName(QString::fromUtf8("placeholderLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, placeholderLabel);

        placeholderComboBox = new KComboBox(placeholder);
        placeholderComboBox->setObjectName(QString::fromUtf8("placeholderComboBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, placeholderComboBox);

        shortFormLabel = new QLabel(placeholder);
        shortFormLabel->setObjectName(QString::fromUtf8("shortFormLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, shortFormLabel);

        shortFormCheckBox = new QCheckBox(placeholder);
        shortFormCheckBox->setObjectName(QString::fromUtf8("shortFormCheckBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, shortFormCheckBox);

        leadingZerosLabel = new QLabel(placeholder);
        leadingZerosLabel->setObjectName(QString::fromUtf8("leadingZerosLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, leadingZerosLabel);

        leadingZerosCheckBox = new QCheckBox(placeholder);
        leadingZerosCheckBox->setObjectName(QString::fromUtf8("leadingZerosCheckBox"));

        formLayout->setWidget(3, QFormLayout::FieldRole, leadingZerosCheckBox);

        hoursModeLabel = new QLabel(placeholder);
        hoursModeLabel->setObjectName(QString::fromUtf8("hoursModeLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, hoursModeLabel);

        hoursModeCheckBox = new QCheckBox(placeholder);
        hoursModeCheckBox->setObjectName(QString::fromUtf8("hoursModeCheckBox"));
        hoursModeCheckBox->setTristate(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, hoursModeCheckBox);

        textualFormLabel = new QLabel(placeholder);
        textualFormLabel->setObjectName(QString::fromUtf8("textualFormLabel"));

        formLayout->setWidget(5, QFormLayout::LabelRole, textualFormLabel);

        textualFormCheckBox = new QCheckBox(placeholder);
        textualFormCheckBox->setObjectName(QString::fromUtf8("textualFormCheckBox"));

        formLayout->setWidget(5, QFormLayout::FieldRole, textualFormCheckBox);

        possessiveFormLabel = new QLabel(placeholder);
        possessiveFormLabel->setObjectName(QString::fromUtf8("possessiveFormLabel"));

        formLayout->setWidget(6, QFormLayout::LabelRole, possessiveFormLabel);

        possessiveFormCheckBox = new QCheckBox(placeholder);
        possessiveFormCheckBox->setObjectName(QString::fromUtf8("possessiveFormCheckBox"));
        possessiveFormCheckBox->setTristate(true);

        formLayout->setWidget(6, QFormLayout::FieldRole, possessiveFormCheckBox);

        timezoneModeComboBox = new KComboBox(placeholder);
        timezoneModeComboBox->setObjectName(QString::fromUtf8("timezoneModeComboBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, timezoneModeComboBox);

        timezoneModeLabel = new QLabel(placeholder);
        timezoneModeLabel->setObjectName(QString::fromUtf8("timezoneModeLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, timezoneModeLabel);


        verticalLayout->addLayout(formLayout);

        groupBox = new QGroupBox(placeholder);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        previewLabel = new QLabel(groupBox);
        previewLabel->setObjectName(QString::fromUtf8("previewLabel"));

        verticalLayout_2->addWidget(previewLabel);


        verticalLayout->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

#ifndef UI_QT_NO_SHORTCUT
        placeholderLabel->setBuddy(placeholderComboBox);
        shortFormLabel->setBuddy(shortFormCheckBox);
        leadingZerosLabel->setBuddy(leadingZerosCheckBox);
        hoursModeLabel->setBuddy(hoursModeCheckBox);
        textualFormLabel->setBuddy(textualFormCheckBox);
        possessiveFormLabel->setBuddy(possessiveFormCheckBox);
        timezoneModeLabel->setBuddy(timezoneModeComboBox);
#endif // QT_NO_SHORTCUT

        retranslateUi(placeholder);

        QMetaObject::connectSlotsByName(placeholder);
    } // setupUi

    void retranslateUi(QWidget *placeholder)
    {
        placeholder->setWindowTitle(tr2i18n("Insert Format Component", 0));
        placeholderLabel->setText(tr2i18n("Format component:", 0));
        shortFormLabel->setText(tr2i18n("Short form", 0));
        shortFormCheckBox->setText(QString());
        leadingZerosLabel->setText(tr2i18n("Show leading zeros", 0));
        leadingZerosCheckBox->setText(QString());
        hoursModeLabel->setText(tr2i18n("12 hours mode", 0));
        textualFormLabel->setText(tr2i18n("Textual form", 0));
        textualFormCheckBox->setText(QString());
        possessiveFormLabel->setText(tr2i18n("Possessive form", 0));
        possessiveFormCheckBox->setText(QString());
        timezoneModeComboBox->clear();
        timezoneModeComboBox->insertItems(0, QStringList()
         << tr2i18n("Area", 0)
         << tr2i18n("Abbreviation", 0)
         << tr2i18n("Offset to UTC", 0)
        );
        timezoneModeLabel->setText(tr2i18n("Timezone mode:", 0));
        groupBox->setTitle(tr2i18n("Preview", 0));
        previewLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class placeholder: public Ui_placeholder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PLACEHOLDER_H

