
/*

  KLayout Layout Viewer
  Copyright (C) 2006-2020 Matthias Koefferlein

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

*/

/**
*  @file gsiDeclQRegularExpressionValidator.cc 
*
*  DO NOT EDIT THIS FILE. 
*  This file has been created automatically
*/

#include <QRegularExpressionValidator>
#include <QChildEvent>
#include <QEvent>
#include <QLocale>
#include <QMetaMethod>
#include <QObject>
#include <QRegularExpression>
#include <QThread>
#include <QTimerEvent>
#include "gsiQt.h"
#include "gsiQtGuiCommon.h"
#include "gsiDeclQtGuiTypeTraits.h"
#include <memory>

// -----------------------------------------------------------------------
// class QRegularExpressionValidator

//  get static meta object

static void _init_smo (qt_gsi::GenericStaticMethod *decl)
{
  decl->set_return<const QMetaObject &> ();
}

static void _call_smo (const qt_gsi::GenericStaticMethod *, gsi::SerialArgs &, gsi::SerialArgs &ret) 
{
  ret.write<const QMetaObject &> (QRegularExpressionValidator::staticMetaObject);
}


// QRegularExpression QRegularExpressionValidator::regularExpression()


static void _init_f_regularExpression_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QRegularExpression > ();
}

static void _call_f_regularExpression_c0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  ret.write<QRegularExpression > ((QRegularExpression)((QRegularExpressionValidator *)cls)->regularExpression ());
}


// void QRegularExpressionValidator::setRegularExpression(const QRegularExpression &re)


static void _init_f_setRegularExpression_3188 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("re");
  decl->add_arg<const QRegularExpression & > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_setRegularExpression_3188 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  const QRegularExpression &arg1 = gsi::arg_reader<const QRegularExpression & >() (args, heap);
  __SUPPRESS_UNUSED_WARNING(ret);
  ((QRegularExpressionValidator *)cls)->setRegularExpression (arg1);
}


// QValidator::State QRegularExpressionValidator::validate(QString &input, int &pos)


static void _init_f_validate_c2171 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("input");
  decl->add_arg<QString & > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("pos");
  decl->add_arg<int & > (argspec_1);
  decl->set_return<qt_gsi::Converter<QValidator::State>::target_type > ();
}

static void _call_f_validate_c2171 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  QString &arg1 = gsi::arg_reader<QString & >() (args, heap);
  int &arg2 = gsi::arg_reader<int & >() (args, heap);
  ret.write<qt_gsi::Converter<QValidator::State>::target_type > ((qt_gsi::Converter<QValidator::State>::target_type)qt_gsi::CppToQtAdaptor<QValidator::State>(((QRegularExpressionValidator *)cls)->validate (arg1, arg2)));
}


// static QString QRegularExpressionValidator::tr(const char *s, const char *c, int n)


static void _init_f_tr_4013 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("s");
  decl->add_arg<const char * > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("c", true, "__null");
  decl->add_arg<const char * > (argspec_1);
  static gsi::ArgSpecBase argspec_2 ("n", true, "-1");
  decl->add_arg<int > (argspec_2);
  decl->set_return<QString > ();
}

static void _call_f_tr_4013 (const qt_gsi::GenericStaticMethod * /*decl*/, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  const char *arg1 = gsi::arg_reader<const char * >() (args, heap);
  const char *arg2 = args ? gsi::arg_reader<const char * >() (args, heap) : gsi::arg_maker<const char * >() (__null, heap);
  int arg3 = args ? gsi::arg_reader<int >() (args, heap) : gsi::arg_maker<int >() (-1, heap);
  ret.write<QString > ((QString)QRegularExpressionValidator::tr (arg1, arg2, arg3));
}


// static QString QRegularExpressionValidator::trUtf8(const char *s, const char *c, int n)


static void _init_f_trUtf8_4013 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("s");
  decl->add_arg<const char * > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("c", true, "__null");
  decl->add_arg<const char * > (argspec_1);
  static gsi::ArgSpecBase argspec_2 ("n", true, "-1");
  decl->add_arg<int > (argspec_2);
  decl->set_return<QString > ();
}

static void _call_f_trUtf8_4013 (const qt_gsi::GenericStaticMethod * /*decl*/, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  const char *arg1 = gsi::arg_reader<const char * >() (args, heap);
  const char *arg2 = args ? gsi::arg_reader<const char * >() (args, heap) : gsi::arg_maker<const char * >() (__null, heap);
  int arg3 = args ? gsi::arg_reader<int >() (args, heap) : gsi::arg_maker<int >() (-1, heap);
  ret.write<QString > ((QString)QRegularExpressionValidator::trUtf8 (arg1, arg2, arg3));
}


namespace gsi
{

static gsi::Methods methods_QRegularExpressionValidator () {
  gsi::Methods methods;
  methods += new qt_gsi::GenericStaticMethod ("staticMetaObject", "@brief Obtains the static MetaObject for this class.", &_init_smo, &_call_smo);
  methods += new qt_gsi::GenericMethod (":regularExpression", "@brief Method QRegularExpression QRegularExpressionValidator::regularExpression()\n", true, &_init_f_regularExpression_c0, &_call_f_regularExpression_c0);
  methods += new qt_gsi::GenericMethod ("setRegularExpression|regularExpression=", "@brief Method void QRegularExpressionValidator::setRegularExpression(const QRegularExpression &re)\n", false, &_init_f_setRegularExpression_3188, &_call_f_setRegularExpression_3188);
  methods += new qt_gsi::GenericMethod ("validate", "@brief Method QValidator::State QRegularExpressionValidator::validate(QString &input, int &pos)\nThis is a reimplementation of QValidator::validate", true, &_init_f_validate_c2171, &_call_f_validate_c2171);
  methods += gsi::qt_signal ("changed()", "changed", "@brief Signal declaration for QRegularExpressionValidator::changed()\nYou can bind a procedure to this signal.");
  methods += gsi::qt_signal<QObject * > ("destroyed(QObject *)", "destroyed", gsi::arg("arg1"), "@brief Signal declaration for QRegularExpressionValidator::destroyed(QObject *)\nYou can bind a procedure to this signal.");
  methods += gsi::qt_signal<const QRegularExpression & > ("regularExpressionChanged(const QRegularExpression &)", "regularExpressionChanged", gsi::arg("re"), "@brief Signal declaration for QRegularExpressionValidator::regularExpressionChanged(const QRegularExpression &re)\nYou can bind a procedure to this signal.");
  methods += new qt_gsi::GenericStaticMethod ("tr", "@brief Static method QString QRegularExpressionValidator::tr(const char *s, const char *c, int n)\nThis method is static and can be called without an instance.", &_init_f_tr_4013, &_call_f_tr_4013);
  methods += new qt_gsi::GenericStaticMethod ("trUtf8", "@brief Static method QString QRegularExpressionValidator::trUtf8(const char *s, const char *c, int n)\nThis method is static and can be called without an instance.", &_init_f_trUtf8_4013, &_call_f_trUtf8_4013);
  return methods;
}

gsi::Class<QValidator> &qtdecl_QValidator ();

qt_gsi::QtNativeClass<QRegularExpressionValidator> decl_QRegularExpressionValidator (qtdecl_QValidator (), "QtGui", "QRegularExpressionValidator_Native",
  methods_QRegularExpressionValidator (),
  "@hide\n@alias QRegularExpressionValidator");

GSI_QTGUI_PUBLIC gsi::Class<QRegularExpressionValidator> &qtdecl_QRegularExpressionValidator () { return decl_QRegularExpressionValidator; }

}


class QRegularExpressionValidator_Adaptor : public QRegularExpressionValidator, public qt_gsi::QtObjectBase
{
public:

  virtual ~QRegularExpressionValidator_Adaptor();

  //  [adaptor ctor] QRegularExpressionValidator::QRegularExpressionValidator(QObject *parent)
  QRegularExpressionValidator_Adaptor() : QRegularExpressionValidator()
  {
    qt_gsi::QtObjectBase::init (this);
  }

  //  [adaptor ctor] QRegularExpressionValidator::QRegularExpressionValidator(QObject *parent)
  QRegularExpressionValidator_Adaptor(QObject *parent) : QRegularExpressionValidator(parent)
  {
    qt_gsi::QtObjectBase::init (this);
  }

  //  [adaptor ctor] QRegularExpressionValidator::QRegularExpressionValidator(const QRegularExpression &re, QObject *parent)
  QRegularExpressionValidator_Adaptor(const QRegularExpression &re) : QRegularExpressionValidator(re)
  {
    qt_gsi::QtObjectBase::init (this);
  }

  //  [adaptor ctor] QRegularExpressionValidator::QRegularExpressionValidator(const QRegularExpression &re, QObject *parent)
  QRegularExpressionValidator_Adaptor(const QRegularExpression &re, QObject *parent) : QRegularExpressionValidator(re, parent)
  {
    qt_gsi::QtObjectBase::init (this);
  }

  //  [expose] bool QRegularExpressionValidator::isSignalConnected(const QMetaMethod &signal)
  bool fp_QRegularExpressionValidator_isSignalConnected_c2394 (const QMetaMethod &signal) const {
    return QRegularExpressionValidator::isSignalConnected(signal);
  }

  //  [expose] int QRegularExpressionValidator::receivers(const char *signal)
  int fp_QRegularExpressionValidator_receivers_c1731 (const char *signal) const {
    return QRegularExpressionValidator::receivers(signal);
  }

  //  [expose] QObject *QRegularExpressionValidator::sender()
  QObject * fp_QRegularExpressionValidator_sender_c0 () const {
    return QRegularExpressionValidator::sender();
  }

  //  [expose] int QRegularExpressionValidator::senderSignalIndex()
  int fp_QRegularExpressionValidator_senderSignalIndex_c0 () const {
    return QRegularExpressionValidator::senderSignalIndex();
  }

  //  [emitter impl] void QRegularExpressionValidator::changed()
  void emitter_QRegularExpressionValidator_changed_0()
  {
    emit QRegularExpressionValidator::changed();
  }

  //  [emitter impl] void QRegularExpressionValidator::destroyed(QObject *)
  void emitter_QRegularExpressionValidator_destroyed_1302(QObject *arg1)
  {
    emit QRegularExpressionValidator::destroyed(arg1);
  }

  //  [adaptor impl] bool QRegularExpressionValidator::event(QEvent *)
  bool cbs_event_1217_0(QEvent *arg1)
  {
    return QRegularExpressionValidator::event(arg1);
  }

  virtual bool event(QEvent *arg1)
  {
    if (cb_event_1217_0.can_issue()) {
      return cb_event_1217_0.issue<QRegularExpressionValidator_Adaptor, bool, QEvent *>(&QRegularExpressionValidator_Adaptor::cbs_event_1217_0, arg1);
    } else {
      return QRegularExpressionValidator::event(arg1);
    }
  }

  //  [adaptor impl] bool QRegularExpressionValidator::eventFilter(QObject *, QEvent *)
  bool cbs_eventFilter_2411_0(QObject *arg1, QEvent *arg2)
  {
    return QRegularExpressionValidator::eventFilter(arg1, arg2);
  }

  virtual bool eventFilter(QObject *arg1, QEvent *arg2)
  {
    if (cb_eventFilter_2411_0.can_issue()) {
      return cb_eventFilter_2411_0.issue<QRegularExpressionValidator_Adaptor, bool, QObject *, QEvent *>(&QRegularExpressionValidator_Adaptor::cbs_eventFilter_2411_0, arg1, arg2);
    } else {
      return QRegularExpressionValidator::eventFilter(arg1, arg2);
    }
  }

  //  [adaptor impl] void QRegularExpressionValidator::fixup(QString &)
  void cbs_fixup_c1330_0(QString &arg1) const
  {
    QRegularExpressionValidator::fixup(arg1);
  }

  virtual void fixup(QString &arg1) const
  {
    if (cb_fixup_c1330_0.can_issue()) {
      cb_fixup_c1330_0.issue<QRegularExpressionValidator_Adaptor, QString &>(&QRegularExpressionValidator_Adaptor::cbs_fixup_c1330_0, arg1);
    } else {
      QRegularExpressionValidator::fixup(arg1);
    }
  }

  //  [emitter impl] void QRegularExpressionValidator::regularExpressionChanged(const QRegularExpression &re)
  void emitter_QRegularExpressionValidator_regularExpressionChanged_3188(const QRegularExpression &re)
  {
    emit QRegularExpressionValidator::regularExpressionChanged(re);
  }

  //  [adaptor impl] QValidator::State QRegularExpressionValidator::validate(QString &input, int &pos)
  qt_gsi::Converter<QValidator::State>::target_type cbs_validate_c2171_0(QString &input, int &pos) const
  {
    return qt_gsi::CppToQtAdaptor<QValidator::State>(QRegularExpressionValidator::validate(input, pos));
  }

  virtual QValidator::State validate(QString &input, int &pos) const
  {
    if (cb_validate_c2171_0.can_issue()) {
      return qt_gsi::QtToCppAdaptor<QValidator::State>(cb_validate_c2171_0.issue<QRegularExpressionValidator_Adaptor, qt_gsi::Converter<QValidator::State>::target_type, QString &, int &>(&QRegularExpressionValidator_Adaptor::cbs_validate_c2171_0, input, pos)).cref();
    } else {
      return QRegularExpressionValidator::validate(input, pos);
    }
  }

  //  [adaptor impl] void QRegularExpressionValidator::childEvent(QChildEvent *)
  void cbs_childEvent_1701_0(QChildEvent *arg1)
  {
    QRegularExpressionValidator::childEvent(arg1);
  }

  virtual void childEvent(QChildEvent *arg1)
  {
    if (cb_childEvent_1701_0.can_issue()) {
      cb_childEvent_1701_0.issue<QRegularExpressionValidator_Adaptor, QChildEvent *>(&QRegularExpressionValidator_Adaptor::cbs_childEvent_1701_0, arg1);
    } else {
      QRegularExpressionValidator::childEvent(arg1);
    }
  }

  //  [adaptor impl] void QRegularExpressionValidator::customEvent(QEvent *)
  void cbs_customEvent_1217_0(QEvent *arg1)
  {
    QRegularExpressionValidator::customEvent(arg1);
  }

  virtual void customEvent(QEvent *arg1)
  {
    if (cb_customEvent_1217_0.can_issue()) {
      cb_customEvent_1217_0.issue<QRegularExpressionValidator_Adaptor, QEvent *>(&QRegularExpressionValidator_Adaptor::cbs_customEvent_1217_0, arg1);
    } else {
      QRegularExpressionValidator::customEvent(arg1);
    }
  }

  //  [adaptor impl] void QRegularExpressionValidator::disconnectNotify(const QMetaMethod &signal)
  void cbs_disconnectNotify_2394_0(const QMetaMethod &signal)
  {
    QRegularExpressionValidator::disconnectNotify(signal);
  }

  virtual void disconnectNotify(const QMetaMethod &signal)
  {
    if (cb_disconnectNotify_2394_0.can_issue()) {
      cb_disconnectNotify_2394_0.issue<QRegularExpressionValidator_Adaptor, const QMetaMethod &>(&QRegularExpressionValidator_Adaptor::cbs_disconnectNotify_2394_0, signal);
    } else {
      QRegularExpressionValidator::disconnectNotify(signal);
    }
  }

  //  [adaptor impl] void QRegularExpressionValidator::timerEvent(QTimerEvent *)
  void cbs_timerEvent_1730_0(QTimerEvent *arg1)
  {
    QRegularExpressionValidator::timerEvent(arg1);
  }

  virtual void timerEvent(QTimerEvent *arg1)
  {
    if (cb_timerEvent_1730_0.can_issue()) {
      cb_timerEvent_1730_0.issue<QRegularExpressionValidator_Adaptor, QTimerEvent *>(&QRegularExpressionValidator_Adaptor::cbs_timerEvent_1730_0, arg1);
    } else {
      QRegularExpressionValidator::timerEvent(arg1);
    }
  }

  gsi::Callback cb_event_1217_0;
  gsi::Callback cb_eventFilter_2411_0;
  gsi::Callback cb_fixup_c1330_0;
  gsi::Callback cb_validate_c2171_0;
  gsi::Callback cb_childEvent_1701_0;
  gsi::Callback cb_customEvent_1217_0;
  gsi::Callback cb_disconnectNotify_2394_0;
  gsi::Callback cb_timerEvent_1730_0;
};

QRegularExpressionValidator_Adaptor::~QRegularExpressionValidator_Adaptor() { }

//  Constructor QRegularExpressionValidator::QRegularExpressionValidator(QObject *parent) (adaptor class)

static void _init_ctor_QRegularExpressionValidator_Adaptor_1302 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("parent", true, "0");
  decl->add_arg<QObject * > (argspec_0);
  decl->set_return_new<QRegularExpressionValidator_Adaptor> ();
}

static void _call_ctor_QRegularExpressionValidator_Adaptor_1302 (const qt_gsi::GenericStaticMethod * /*decl*/, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  QObject *arg1 = args ? gsi::arg_reader<QObject * >() (args, heap) : gsi::arg_maker<QObject * >() (0, heap);
  ret.write<QRegularExpressionValidator_Adaptor *> (new QRegularExpressionValidator_Adaptor (arg1));
}


//  Constructor QRegularExpressionValidator::QRegularExpressionValidator(const QRegularExpression &re, QObject *parent) (adaptor class)

static void _init_ctor_QRegularExpressionValidator_Adaptor_4382 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("re");
  decl->add_arg<const QRegularExpression & > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("parent", true, "0");
  decl->add_arg<QObject * > (argspec_1);
  decl->set_return_new<QRegularExpressionValidator_Adaptor> ();
}

static void _call_ctor_QRegularExpressionValidator_Adaptor_4382 (const qt_gsi::GenericStaticMethod * /*decl*/, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  const QRegularExpression &arg1 = gsi::arg_reader<const QRegularExpression & >() (args, heap);
  QObject *arg2 = args ? gsi::arg_reader<QObject * >() (args, heap) : gsi::arg_maker<QObject * >() (0, heap);
  ret.write<QRegularExpressionValidator_Adaptor *> (new QRegularExpressionValidator_Adaptor (arg1, arg2));
}


// emitter void QRegularExpressionValidator::changed()

static void _init_emitter_changed_0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<void > ();
}

static void _call_emitter_changed_0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs & /*ret*/) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  ((QRegularExpressionValidator_Adaptor *)cls)->emitter_QRegularExpressionValidator_changed_0 ();
}


// void QRegularExpressionValidator::childEvent(QChildEvent *)

static void _init_cbs_childEvent_1701_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QChildEvent * > (argspec_0);
  decl->set_return<void > ();
}

static void _call_cbs_childEvent_1701_0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  QChildEvent *arg1 = args.read<QChildEvent * > (heap);
  __SUPPRESS_UNUSED_WARNING(ret);
  ((QRegularExpressionValidator_Adaptor *)cls)->cbs_childEvent_1701_0 (arg1);
}

static void _set_callback_cbs_childEvent_1701_0 (void *cls, const gsi::Callback &cb)
{
  ((QRegularExpressionValidator_Adaptor *)cls)->cb_childEvent_1701_0 = cb;
}


// void QRegularExpressionValidator::customEvent(QEvent *)

static void _init_cbs_customEvent_1217_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QEvent * > (argspec_0);
  decl->set_return<void > ();
}

static void _call_cbs_customEvent_1217_0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  QEvent *arg1 = args.read<QEvent * > (heap);
  __SUPPRESS_UNUSED_WARNING(ret);
  ((QRegularExpressionValidator_Adaptor *)cls)->cbs_customEvent_1217_0 (arg1);
}

static void _set_callback_cbs_customEvent_1217_0 (void *cls, const gsi::Callback &cb)
{
  ((QRegularExpressionValidator_Adaptor *)cls)->cb_customEvent_1217_0 = cb;
}


// emitter void QRegularExpressionValidator::destroyed(QObject *)

static void _init_emitter_destroyed_1302 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1", true, "0");
  decl->add_arg<QObject * > (argspec_0);
  decl->set_return<void > ();
}

static void _call_emitter_destroyed_1302 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs & /*ret*/) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  QObject *arg1 = args ? gsi::arg_reader<QObject * >() (args, heap) : gsi::arg_maker<QObject * >() (0, heap);
  ((QRegularExpressionValidator_Adaptor *)cls)->emitter_QRegularExpressionValidator_destroyed_1302 (arg1);
}


// void QRegularExpressionValidator::disconnectNotify(const QMetaMethod &signal)

static void _init_cbs_disconnectNotify_2394_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("signal");
  decl->add_arg<const QMetaMethod & > (argspec_0);
  decl->set_return<void > ();
}

static void _call_cbs_disconnectNotify_2394_0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  const QMetaMethod &arg1 = args.read<const QMetaMethod & > (heap);
  __SUPPRESS_UNUSED_WARNING(ret);
  ((QRegularExpressionValidator_Adaptor *)cls)->cbs_disconnectNotify_2394_0 (arg1);
}

static void _set_callback_cbs_disconnectNotify_2394_0 (void *cls, const gsi::Callback &cb)
{
  ((QRegularExpressionValidator_Adaptor *)cls)->cb_disconnectNotify_2394_0 = cb;
}


// bool QRegularExpressionValidator::event(QEvent *)

static void _init_cbs_event_1217_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QEvent * > (argspec_0);
  decl->set_return<bool > ();
}

static void _call_cbs_event_1217_0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  QEvent *arg1 = args.read<QEvent * > (heap);
  ret.write<bool > ((bool)((QRegularExpressionValidator_Adaptor *)cls)->cbs_event_1217_0 (arg1));
}

static void _set_callback_cbs_event_1217_0 (void *cls, const gsi::Callback &cb)
{
  ((QRegularExpressionValidator_Adaptor *)cls)->cb_event_1217_0 = cb;
}


// bool QRegularExpressionValidator::eventFilter(QObject *, QEvent *)

static void _init_cbs_eventFilter_2411_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QObject * > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("arg2");
  decl->add_arg<QEvent * > (argspec_1);
  decl->set_return<bool > ();
}

static void _call_cbs_eventFilter_2411_0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  QObject *arg1 = args.read<QObject * > (heap);
  QEvent *arg2 = args.read<QEvent * > (heap);
  ret.write<bool > ((bool)((QRegularExpressionValidator_Adaptor *)cls)->cbs_eventFilter_2411_0 (arg1, arg2));
}

static void _set_callback_cbs_eventFilter_2411_0 (void *cls, const gsi::Callback &cb)
{
  ((QRegularExpressionValidator_Adaptor *)cls)->cb_eventFilter_2411_0 = cb;
}


// void QRegularExpressionValidator::fixup(QString &)

static void _init_cbs_fixup_c1330_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QString & > (argspec_0);
  decl->set_return<void > ();
}

static void _call_cbs_fixup_c1330_0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  QString &arg1 = args.read<QString & > (heap);
  __SUPPRESS_UNUSED_WARNING(ret);
  ((QRegularExpressionValidator_Adaptor *)cls)->cbs_fixup_c1330_0 (arg1);
}

static void _set_callback_cbs_fixup_c1330_0 (void *cls, const gsi::Callback &cb)
{
  ((QRegularExpressionValidator_Adaptor *)cls)->cb_fixup_c1330_0 = cb;
}


// exposed bool QRegularExpressionValidator::isSignalConnected(const QMetaMethod &signal)

static void _init_fp_isSignalConnected_c2394 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("signal");
  decl->add_arg<const QMetaMethod & > (argspec_0);
  decl->set_return<bool > ();
}

static void _call_fp_isSignalConnected_c2394 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  const QMetaMethod &arg1 = gsi::arg_reader<const QMetaMethod & >() (args, heap);
  ret.write<bool > ((bool)((QRegularExpressionValidator_Adaptor *)cls)->fp_QRegularExpressionValidator_isSignalConnected_c2394 (arg1));
}


// exposed int QRegularExpressionValidator::receivers(const char *signal)

static void _init_fp_receivers_c1731 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("signal");
  decl->add_arg<const char * > (argspec_0);
  decl->set_return<int > ();
}

static void _call_fp_receivers_c1731 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  const char *arg1 = gsi::arg_reader<const char * >() (args, heap);
  ret.write<int > ((int)((QRegularExpressionValidator_Adaptor *)cls)->fp_QRegularExpressionValidator_receivers_c1731 (arg1));
}


// emitter void QRegularExpressionValidator::regularExpressionChanged(const QRegularExpression &re)

static void _init_emitter_regularExpressionChanged_3188 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("re");
  decl->add_arg<const QRegularExpression & > (argspec_0);
  decl->set_return<void > ();
}

static void _call_emitter_regularExpressionChanged_3188 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs & /*ret*/) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  const QRegularExpression &arg1 = gsi::arg_reader<const QRegularExpression & >() (args, heap);
  ((QRegularExpressionValidator_Adaptor *)cls)->emitter_QRegularExpressionValidator_regularExpressionChanged_3188 (arg1);
}


// exposed QObject *QRegularExpressionValidator::sender()

static void _init_fp_sender_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QObject * > ();
}

static void _call_fp_sender_c0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  ret.write<QObject * > ((QObject *)((QRegularExpressionValidator_Adaptor *)cls)->fp_QRegularExpressionValidator_sender_c0 ());
}


// exposed int QRegularExpressionValidator::senderSignalIndex()

static void _init_fp_senderSignalIndex_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<int > ();
}

static void _call_fp_senderSignalIndex_c0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  ret.write<int > ((int)((QRegularExpressionValidator_Adaptor *)cls)->fp_QRegularExpressionValidator_senderSignalIndex_c0 ());
}


// void QRegularExpressionValidator::timerEvent(QTimerEvent *)

static void _init_cbs_timerEvent_1730_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QTimerEvent * > (argspec_0);
  decl->set_return<void > ();
}

static void _call_cbs_timerEvent_1730_0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  QTimerEvent *arg1 = args.read<QTimerEvent * > (heap);
  __SUPPRESS_UNUSED_WARNING(ret);
  ((QRegularExpressionValidator_Adaptor *)cls)->cbs_timerEvent_1730_0 (arg1);
}

static void _set_callback_cbs_timerEvent_1730_0 (void *cls, const gsi::Callback &cb)
{
  ((QRegularExpressionValidator_Adaptor *)cls)->cb_timerEvent_1730_0 = cb;
}


// QValidator::State QRegularExpressionValidator::validate(QString &input, int &pos)

static void _init_cbs_validate_c2171_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("input");
  decl->add_arg<QString & > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("pos");
  decl->add_arg<int & > (argspec_1);
  decl->set_return<qt_gsi::Converter<QValidator::State>::target_type > ();
}

static void _call_cbs_validate_c2171_0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  QString &arg1 = args.read<QString & > (heap);
  int &arg2 = args.read<int & > (heap);
  ret.write<qt_gsi::Converter<QValidator::State>::target_type > ((qt_gsi::Converter<QValidator::State>::target_type)((QRegularExpressionValidator_Adaptor *)cls)->cbs_validate_c2171_0 (arg1, arg2));
}

static void _set_callback_cbs_validate_c2171_0 (void *cls, const gsi::Callback &cb)
{
  ((QRegularExpressionValidator_Adaptor *)cls)->cb_validate_c2171_0 = cb;
}


namespace gsi
{

gsi::Class<QRegularExpressionValidator> &qtdecl_QRegularExpressionValidator ();

static gsi::Methods methods_QRegularExpressionValidator_Adaptor () {
  gsi::Methods methods;
  methods += new qt_gsi::GenericStaticMethod ("new", "@brief Constructor QRegularExpressionValidator::QRegularExpressionValidator(QObject *parent)\nThis method creates an object of class QRegularExpressionValidator.", &_init_ctor_QRegularExpressionValidator_Adaptor_1302, &_call_ctor_QRegularExpressionValidator_Adaptor_1302);
  methods += new qt_gsi::GenericStaticMethod ("new", "@brief Constructor QRegularExpressionValidator::QRegularExpressionValidator(const QRegularExpression &re, QObject *parent)\nThis method creates an object of class QRegularExpressionValidator.", &_init_ctor_QRegularExpressionValidator_Adaptor_4382, &_call_ctor_QRegularExpressionValidator_Adaptor_4382);
  methods += new qt_gsi::GenericMethod ("emit_changed", "@brief Emitter for signal void QRegularExpressionValidator::changed()\nCall this method to emit this signal.", false, &_init_emitter_changed_0, &_call_emitter_changed_0);
  methods += new qt_gsi::GenericMethod ("*childEvent", "@brief Virtual method void QRegularExpressionValidator::childEvent(QChildEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_childEvent_1701_0, &_call_cbs_childEvent_1701_0);
  methods += new qt_gsi::GenericMethod ("*childEvent", "@hide", false, &_init_cbs_childEvent_1701_0, &_call_cbs_childEvent_1701_0, &_set_callback_cbs_childEvent_1701_0);
  methods += new qt_gsi::GenericMethod ("*customEvent", "@brief Virtual method void QRegularExpressionValidator::customEvent(QEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_customEvent_1217_0, &_call_cbs_customEvent_1217_0);
  methods += new qt_gsi::GenericMethod ("*customEvent", "@hide", false, &_init_cbs_customEvent_1217_0, &_call_cbs_customEvent_1217_0, &_set_callback_cbs_customEvent_1217_0);
  methods += new qt_gsi::GenericMethod ("emit_destroyed", "@brief Emitter for signal void QRegularExpressionValidator::destroyed(QObject *)\nCall this method to emit this signal.", false, &_init_emitter_destroyed_1302, &_call_emitter_destroyed_1302);
  methods += new qt_gsi::GenericMethod ("*disconnectNotify", "@brief Virtual method void QRegularExpressionValidator::disconnectNotify(const QMetaMethod &signal)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_disconnectNotify_2394_0, &_call_cbs_disconnectNotify_2394_0);
  methods += new qt_gsi::GenericMethod ("*disconnectNotify", "@hide", false, &_init_cbs_disconnectNotify_2394_0, &_call_cbs_disconnectNotify_2394_0, &_set_callback_cbs_disconnectNotify_2394_0);
  methods += new qt_gsi::GenericMethod ("event", "@brief Virtual method bool QRegularExpressionValidator::event(QEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_event_1217_0, &_call_cbs_event_1217_0);
  methods += new qt_gsi::GenericMethod ("event", "@hide", false, &_init_cbs_event_1217_0, &_call_cbs_event_1217_0, &_set_callback_cbs_event_1217_0);
  methods += new qt_gsi::GenericMethod ("eventFilter", "@brief Virtual method bool QRegularExpressionValidator::eventFilter(QObject *, QEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_eventFilter_2411_0, &_call_cbs_eventFilter_2411_0);
  methods += new qt_gsi::GenericMethod ("eventFilter", "@hide", false, &_init_cbs_eventFilter_2411_0, &_call_cbs_eventFilter_2411_0, &_set_callback_cbs_eventFilter_2411_0);
  methods += new qt_gsi::GenericMethod ("fixup", "@brief Virtual method void QRegularExpressionValidator::fixup(QString &)\nThis method can be reimplemented in a derived class.", true, &_init_cbs_fixup_c1330_0, &_call_cbs_fixup_c1330_0);
  methods += new qt_gsi::GenericMethod ("fixup", "@hide", true, &_init_cbs_fixup_c1330_0, &_call_cbs_fixup_c1330_0, &_set_callback_cbs_fixup_c1330_0);
  methods += new qt_gsi::GenericMethod ("*isSignalConnected", "@brief Method bool QRegularExpressionValidator::isSignalConnected(const QMetaMethod &signal)\nThis method is protected and can only be called from inside a derived class.", true, &_init_fp_isSignalConnected_c2394, &_call_fp_isSignalConnected_c2394);
  methods += new qt_gsi::GenericMethod ("*receivers", "@brief Method int QRegularExpressionValidator::receivers(const char *signal)\nThis method is protected and can only be called from inside a derived class.", true, &_init_fp_receivers_c1731, &_call_fp_receivers_c1731);
  methods += new qt_gsi::GenericMethod ("emit_regularExpressionChanged", "@brief Emitter for signal void QRegularExpressionValidator::regularExpressionChanged(const QRegularExpression &re)\nCall this method to emit this signal.", false, &_init_emitter_regularExpressionChanged_3188, &_call_emitter_regularExpressionChanged_3188);
  methods += new qt_gsi::GenericMethod ("*sender", "@brief Method QObject *QRegularExpressionValidator::sender()\nThis method is protected and can only be called from inside a derived class.", true, &_init_fp_sender_c0, &_call_fp_sender_c0);
  methods += new qt_gsi::GenericMethod ("*senderSignalIndex", "@brief Method int QRegularExpressionValidator::senderSignalIndex()\nThis method is protected and can only be called from inside a derived class.", true, &_init_fp_senderSignalIndex_c0, &_call_fp_senderSignalIndex_c0);
  methods += new qt_gsi::GenericMethod ("*timerEvent", "@brief Virtual method void QRegularExpressionValidator::timerEvent(QTimerEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_timerEvent_1730_0, &_call_cbs_timerEvent_1730_0);
  methods += new qt_gsi::GenericMethod ("*timerEvent", "@hide", false, &_init_cbs_timerEvent_1730_0, &_call_cbs_timerEvent_1730_0, &_set_callback_cbs_timerEvent_1730_0);
  methods += new qt_gsi::GenericMethod ("validate", "@brief Virtual method QValidator::State QRegularExpressionValidator::validate(QString &input, int &pos)\nThis method can be reimplemented in a derived class.", true, &_init_cbs_validate_c2171_0, &_call_cbs_validate_c2171_0);
  methods += new qt_gsi::GenericMethod ("validate", "@hide", true, &_init_cbs_validate_c2171_0, &_call_cbs_validate_c2171_0, &_set_callback_cbs_validate_c2171_0);
  return methods;
}

gsi::Class<QRegularExpressionValidator_Adaptor> decl_QRegularExpressionValidator_Adaptor (qtdecl_QRegularExpressionValidator (), "QtGui", "QRegularExpressionValidator",
  methods_QRegularExpressionValidator_Adaptor (),
  "@qt\n@brief Binding of QRegularExpressionValidator");

}

