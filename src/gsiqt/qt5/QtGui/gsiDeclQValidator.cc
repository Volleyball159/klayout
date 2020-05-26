
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
*  @file gsiDeclQValidator.cc 
*
*  DO NOT EDIT THIS FILE. 
*  This file has been created automatically
*/

#include <QValidator>
#include <QChildEvent>
#include <QEvent>
#include <QLocale>
#include <QMetaMethod>
#include <QObject>
#include <QThread>
#include <QTimerEvent>
#include "gsiQt.h"
#include "gsiQtGuiCommon.h"
#include "gsiDeclQtGuiTypeTraits.h"
#include <memory>

// -----------------------------------------------------------------------
// class QValidator

//  get static meta object

static void _init_smo (qt_gsi::GenericStaticMethod *decl)
{
  decl->set_return<const QMetaObject &> ();
}

static void _call_smo (const qt_gsi::GenericStaticMethod *, gsi::SerialArgs &, gsi::SerialArgs &ret) 
{
  ret.write<const QMetaObject &> (QValidator::staticMetaObject);
}


// void QValidator::fixup(QString &)


static void _init_f_fixup_c1330 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QString & > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_fixup_c1330 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  QString &arg1 = gsi::arg_reader<QString & >() (args, heap);
  __SUPPRESS_UNUSED_WARNING(ret);
  ((QValidator *)cls)->fixup (arg1);
}


// QLocale QValidator::locale()


static void _init_f_locale_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QLocale > ();
}

static void _call_f_locale_c0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  ret.write<QLocale > ((QLocale)((QValidator *)cls)->locale ());
}


// void QValidator::setLocale(const QLocale &locale)


static void _init_f_setLocale_1986 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("locale");
  decl->add_arg<const QLocale & > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_setLocale_1986 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  const QLocale &arg1 = gsi::arg_reader<const QLocale & >() (args, heap);
  __SUPPRESS_UNUSED_WARNING(ret);
  ((QValidator *)cls)->setLocale (arg1);
}


// QValidator::State QValidator::validate(QString &, int &)


static void _init_f_validate_c2171 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QString & > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("arg2");
  decl->add_arg<int & > (argspec_1);
  decl->set_return<qt_gsi::Converter<QValidator::State>::target_type > ();
}

static void _call_f_validate_c2171 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  QString &arg1 = gsi::arg_reader<QString & >() (args, heap);
  int &arg2 = gsi::arg_reader<int & >() (args, heap);
  ret.write<qt_gsi::Converter<QValidator::State>::target_type > ((qt_gsi::Converter<QValidator::State>::target_type)qt_gsi::CppToQtAdaptor<QValidator::State>(((QValidator *)cls)->validate (arg1, arg2)));
}


// static QString QValidator::tr(const char *s, const char *c, int n)


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
  ret.write<QString > ((QString)QValidator::tr (arg1, arg2, arg3));
}


// static QString QValidator::trUtf8(const char *s, const char *c, int n)


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
  ret.write<QString > ((QString)QValidator::trUtf8 (arg1, arg2, arg3));
}


namespace gsi
{

static gsi::Methods methods_QValidator () {
  gsi::Methods methods;
  methods += new qt_gsi::GenericStaticMethod ("staticMetaObject", "@brief Obtains the static MetaObject for this class.", &_init_smo, &_call_smo);
  methods += new qt_gsi::GenericMethod ("fixup", "@brief Method void QValidator::fixup(QString &)\n", true, &_init_f_fixup_c1330, &_call_f_fixup_c1330);
  methods += new qt_gsi::GenericMethod (":locale", "@brief Method QLocale QValidator::locale()\n", true, &_init_f_locale_c0, &_call_f_locale_c0);
  methods += new qt_gsi::GenericMethod ("setLocale|locale=", "@brief Method void QValidator::setLocale(const QLocale &locale)\n", false, &_init_f_setLocale_1986, &_call_f_setLocale_1986);
  methods += new qt_gsi::GenericMethod ("validate", "@brief Method QValidator::State QValidator::validate(QString &, int &)\n", true, &_init_f_validate_c2171, &_call_f_validate_c2171);
  methods += gsi::qt_signal ("changed()", "changed", "@brief Signal declaration for QValidator::changed()\nYou can bind a procedure to this signal.");
  methods += gsi::qt_signal<QObject * > ("destroyed(QObject *)", "destroyed", gsi::arg("arg1"), "@brief Signal declaration for QValidator::destroyed(QObject *)\nYou can bind a procedure to this signal.");
  methods += new qt_gsi::GenericStaticMethod ("tr", "@brief Static method QString QValidator::tr(const char *s, const char *c, int n)\nThis method is static and can be called without an instance.", &_init_f_tr_4013, &_call_f_tr_4013);
  methods += new qt_gsi::GenericStaticMethod ("trUtf8", "@brief Static method QString QValidator::trUtf8(const char *s, const char *c, int n)\nThis method is static and can be called without an instance.", &_init_f_trUtf8_4013, &_call_f_trUtf8_4013);
  return methods;
}

gsi::Class<QObject> &qtdecl_QObject ();

qt_gsi::QtNativeClass<QValidator> decl_QValidator (qtdecl_QObject (), "QtGui", "QValidator_Native",
  methods_QValidator (),
  "@hide\n@alias QValidator");

GSI_QTGUI_PUBLIC gsi::Class<QValidator> &qtdecl_QValidator () { return decl_QValidator; }

}


class QValidator_Adaptor : public QValidator, public qt_gsi::QtObjectBase
{
public:

  virtual ~QValidator_Adaptor();

  //  [adaptor ctor] QValidator::QValidator(QObject *parent)
  QValidator_Adaptor() : QValidator()
  {
    qt_gsi::QtObjectBase::init (this);
  }

  //  [adaptor ctor] QValidator::QValidator(QObject *parent)
  QValidator_Adaptor(QObject *parent) : QValidator(parent)
  {
    qt_gsi::QtObjectBase::init (this);
  }

  //  [expose] bool QValidator::isSignalConnected(const QMetaMethod &signal)
  bool fp_QValidator_isSignalConnected_c2394 (const QMetaMethod &signal) const {
    return QValidator::isSignalConnected(signal);
  }

  //  [expose] int QValidator::receivers(const char *signal)
  int fp_QValidator_receivers_c1731 (const char *signal) const {
    return QValidator::receivers(signal);
  }

  //  [expose] QObject *QValidator::sender()
  QObject * fp_QValidator_sender_c0 () const {
    return QValidator::sender();
  }

  //  [expose] int QValidator::senderSignalIndex()
  int fp_QValidator_senderSignalIndex_c0 () const {
    return QValidator::senderSignalIndex();
  }

  //  [emitter impl] void QValidator::changed()
  void emitter_QValidator_changed_0()
  {
    emit QValidator::changed();
  }

  //  [emitter impl] void QValidator::destroyed(QObject *)
  void emitter_QValidator_destroyed_1302(QObject *arg1)
  {
    emit QValidator::destroyed(arg1);
  }

  //  [adaptor impl] bool QValidator::event(QEvent *)
  bool cbs_event_1217_0(QEvent *arg1)
  {
    return QValidator::event(arg1);
  }

  virtual bool event(QEvent *arg1)
  {
    if (cb_event_1217_0.can_issue()) {
      return cb_event_1217_0.issue<QValidator_Adaptor, bool, QEvent *>(&QValidator_Adaptor::cbs_event_1217_0, arg1);
    } else {
      return QValidator::event(arg1);
    }
  }

  //  [adaptor impl] bool QValidator::eventFilter(QObject *, QEvent *)
  bool cbs_eventFilter_2411_0(QObject *arg1, QEvent *arg2)
  {
    return QValidator::eventFilter(arg1, arg2);
  }

  virtual bool eventFilter(QObject *arg1, QEvent *arg2)
  {
    if (cb_eventFilter_2411_0.can_issue()) {
      return cb_eventFilter_2411_0.issue<QValidator_Adaptor, bool, QObject *, QEvent *>(&QValidator_Adaptor::cbs_eventFilter_2411_0, arg1, arg2);
    } else {
      return QValidator::eventFilter(arg1, arg2);
    }
  }

  //  [adaptor impl] void QValidator::fixup(QString &)
  void cbs_fixup_c1330_0(QString &arg1) const
  {
    QValidator::fixup(arg1);
  }

  virtual void fixup(QString &arg1) const
  {
    if (cb_fixup_c1330_0.can_issue()) {
      cb_fixup_c1330_0.issue<QValidator_Adaptor, QString &>(&QValidator_Adaptor::cbs_fixup_c1330_0, arg1);
    } else {
      QValidator::fixup(arg1);
    }
  }

  //  [adaptor impl] QValidator::State QValidator::validate(QString &, int &)
  qt_gsi::Converter<QValidator::State>::target_type cbs_validate_c2171_0(QString &arg1, int &arg2) const
  {
    __SUPPRESS_UNUSED_WARNING (arg1);
    __SUPPRESS_UNUSED_WARNING (arg2);
    throw qt_gsi::AbstractMethodCalledException("validate");
  }

  virtual QValidator::State validate(QString &arg1, int &arg2) const
  {
    if (cb_validate_c2171_0.can_issue()) {
      return qt_gsi::QtToCppAdaptor<QValidator::State>(cb_validate_c2171_0.issue<QValidator_Adaptor, qt_gsi::Converter<QValidator::State>::target_type, QString &, int &>(&QValidator_Adaptor::cbs_validate_c2171_0, arg1, arg2)).cref();
    } else {
      throw qt_gsi::AbstractMethodCalledException("validate");
    }
  }

  //  [adaptor impl] void QValidator::childEvent(QChildEvent *)
  void cbs_childEvent_1701_0(QChildEvent *arg1)
  {
    QValidator::childEvent(arg1);
  }

  virtual void childEvent(QChildEvent *arg1)
  {
    if (cb_childEvent_1701_0.can_issue()) {
      cb_childEvent_1701_0.issue<QValidator_Adaptor, QChildEvent *>(&QValidator_Adaptor::cbs_childEvent_1701_0, arg1);
    } else {
      QValidator::childEvent(arg1);
    }
  }

  //  [adaptor impl] void QValidator::customEvent(QEvent *)
  void cbs_customEvent_1217_0(QEvent *arg1)
  {
    QValidator::customEvent(arg1);
  }

  virtual void customEvent(QEvent *arg1)
  {
    if (cb_customEvent_1217_0.can_issue()) {
      cb_customEvent_1217_0.issue<QValidator_Adaptor, QEvent *>(&QValidator_Adaptor::cbs_customEvent_1217_0, arg1);
    } else {
      QValidator::customEvent(arg1);
    }
  }

  //  [adaptor impl] void QValidator::disconnectNotify(const QMetaMethod &signal)
  void cbs_disconnectNotify_2394_0(const QMetaMethod &signal)
  {
    QValidator::disconnectNotify(signal);
  }

  virtual void disconnectNotify(const QMetaMethod &signal)
  {
    if (cb_disconnectNotify_2394_0.can_issue()) {
      cb_disconnectNotify_2394_0.issue<QValidator_Adaptor, const QMetaMethod &>(&QValidator_Adaptor::cbs_disconnectNotify_2394_0, signal);
    } else {
      QValidator::disconnectNotify(signal);
    }
  }

  //  [adaptor impl] void QValidator::timerEvent(QTimerEvent *)
  void cbs_timerEvent_1730_0(QTimerEvent *arg1)
  {
    QValidator::timerEvent(arg1);
  }

  virtual void timerEvent(QTimerEvent *arg1)
  {
    if (cb_timerEvent_1730_0.can_issue()) {
      cb_timerEvent_1730_0.issue<QValidator_Adaptor, QTimerEvent *>(&QValidator_Adaptor::cbs_timerEvent_1730_0, arg1);
    } else {
      QValidator::timerEvent(arg1);
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

QValidator_Adaptor::~QValidator_Adaptor() { }

//  Constructor QValidator::QValidator(QObject *parent) (adaptor class)

static void _init_ctor_QValidator_Adaptor_1302 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("parent", true, "0");
  decl->add_arg<QObject * > (argspec_0);
  decl->set_return_new<QValidator_Adaptor> ();
}

static void _call_ctor_QValidator_Adaptor_1302 (const qt_gsi::GenericStaticMethod * /*decl*/, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  QObject *arg1 = args ? gsi::arg_reader<QObject * >() (args, heap) : gsi::arg_maker<QObject * >() (0, heap);
  ret.write<QValidator_Adaptor *> (new QValidator_Adaptor (arg1));
}


// emitter void QValidator::changed()

static void _init_emitter_changed_0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<void > ();
}

static void _call_emitter_changed_0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs & /*ret*/) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  ((QValidator_Adaptor *)cls)->emitter_QValidator_changed_0 ();
}


// void QValidator::childEvent(QChildEvent *)

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
  ((QValidator_Adaptor *)cls)->cbs_childEvent_1701_0 (arg1);
}

static void _set_callback_cbs_childEvent_1701_0 (void *cls, const gsi::Callback &cb)
{
  ((QValidator_Adaptor *)cls)->cb_childEvent_1701_0 = cb;
}


// void QValidator::customEvent(QEvent *)

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
  ((QValidator_Adaptor *)cls)->cbs_customEvent_1217_0 (arg1);
}

static void _set_callback_cbs_customEvent_1217_0 (void *cls, const gsi::Callback &cb)
{
  ((QValidator_Adaptor *)cls)->cb_customEvent_1217_0 = cb;
}


// emitter void QValidator::destroyed(QObject *)

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
  ((QValidator_Adaptor *)cls)->emitter_QValidator_destroyed_1302 (arg1);
}


// void QValidator::disconnectNotify(const QMetaMethod &signal)

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
  ((QValidator_Adaptor *)cls)->cbs_disconnectNotify_2394_0 (arg1);
}

static void _set_callback_cbs_disconnectNotify_2394_0 (void *cls, const gsi::Callback &cb)
{
  ((QValidator_Adaptor *)cls)->cb_disconnectNotify_2394_0 = cb;
}


// bool QValidator::event(QEvent *)

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
  ret.write<bool > ((bool)((QValidator_Adaptor *)cls)->cbs_event_1217_0 (arg1));
}

static void _set_callback_cbs_event_1217_0 (void *cls, const gsi::Callback &cb)
{
  ((QValidator_Adaptor *)cls)->cb_event_1217_0 = cb;
}


// bool QValidator::eventFilter(QObject *, QEvent *)

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
  ret.write<bool > ((bool)((QValidator_Adaptor *)cls)->cbs_eventFilter_2411_0 (arg1, arg2));
}

static void _set_callback_cbs_eventFilter_2411_0 (void *cls, const gsi::Callback &cb)
{
  ((QValidator_Adaptor *)cls)->cb_eventFilter_2411_0 = cb;
}


// void QValidator::fixup(QString &)

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
  ((QValidator_Adaptor *)cls)->cbs_fixup_c1330_0 (arg1);
}

static void _set_callback_cbs_fixup_c1330_0 (void *cls, const gsi::Callback &cb)
{
  ((QValidator_Adaptor *)cls)->cb_fixup_c1330_0 = cb;
}


// exposed bool QValidator::isSignalConnected(const QMetaMethod &signal)

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
  ret.write<bool > ((bool)((QValidator_Adaptor *)cls)->fp_QValidator_isSignalConnected_c2394 (arg1));
}


// exposed int QValidator::receivers(const char *signal)

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
  ret.write<int > ((int)((QValidator_Adaptor *)cls)->fp_QValidator_receivers_c1731 (arg1));
}


// exposed QObject *QValidator::sender()

static void _init_fp_sender_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QObject * > ();
}

static void _call_fp_sender_c0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  ret.write<QObject * > ((QObject *)((QValidator_Adaptor *)cls)->fp_QValidator_sender_c0 ());
}


// exposed int QValidator::senderSignalIndex()

static void _init_fp_senderSignalIndex_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<int > ();
}

static void _call_fp_senderSignalIndex_c0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  ret.write<int > ((int)((QValidator_Adaptor *)cls)->fp_QValidator_senderSignalIndex_c0 ());
}


// void QValidator::timerEvent(QTimerEvent *)

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
  ((QValidator_Adaptor *)cls)->cbs_timerEvent_1730_0 (arg1);
}

static void _set_callback_cbs_timerEvent_1730_0 (void *cls, const gsi::Callback &cb)
{
  ((QValidator_Adaptor *)cls)->cb_timerEvent_1730_0 = cb;
}


// QValidator::State QValidator::validate(QString &, int &)

static void _init_cbs_validate_c2171_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QString & > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("arg2");
  decl->add_arg<int & > (argspec_1);
  decl->set_return<qt_gsi::Converter<QValidator::State>::target_type > ();
}

static void _call_cbs_validate_c2171_0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  QString &arg1 = args.read<QString & > (heap);
  int &arg2 = args.read<int & > (heap);
  ret.write<qt_gsi::Converter<QValidator::State>::target_type > ((qt_gsi::Converter<QValidator::State>::target_type)((QValidator_Adaptor *)cls)->cbs_validate_c2171_0 (arg1, arg2));
}

static void _set_callback_cbs_validate_c2171_0 (void *cls, const gsi::Callback &cb)
{
  ((QValidator_Adaptor *)cls)->cb_validate_c2171_0 = cb;
}


namespace gsi
{

gsi::Class<QValidator> &qtdecl_QValidator ();

static gsi::Methods methods_QValidator_Adaptor () {
  gsi::Methods methods;
  methods += new qt_gsi::GenericStaticMethod ("new", "@brief Constructor QValidator::QValidator(QObject *parent)\nThis method creates an object of class QValidator.", &_init_ctor_QValidator_Adaptor_1302, &_call_ctor_QValidator_Adaptor_1302);
  methods += new qt_gsi::GenericMethod ("emit_changed", "@brief Emitter for signal void QValidator::changed()\nCall this method to emit this signal.", false, &_init_emitter_changed_0, &_call_emitter_changed_0);
  methods += new qt_gsi::GenericMethod ("*childEvent", "@brief Virtual method void QValidator::childEvent(QChildEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_childEvent_1701_0, &_call_cbs_childEvent_1701_0);
  methods += new qt_gsi::GenericMethod ("*childEvent", "@hide", false, &_init_cbs_childEvent_1701_0, &_call_cbs_childEvent_1701_0, &_set_callback_cbs_childEvent_1701_0);
  methods += new qt_gsi::GenericMethod ("*customEvent", "@brief Virtual method void QValidator::customEvent(QEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_customEvent_1217_0, &_call_cbs_customEvent_1217_0);
  methods += new qt_gsi::GenericMethod ("*customEvent", "@hide", false, &_init_cbs_customEvent_1217_0, &_call_cbs_customEvent_1217_0, &_set_callback_cbs_customEvent_1217_0);
  methods += new qt_gsi::GenericMethod ("emit_destroyed", "@brief Emitter for signal void QValidator::destroyed(QObject *)\nCall this method to emit this signal.", false, &_init_emitter_destroyed_1302, &_call_emitter_destroyed_1302);
  methods += new qt_gsi::GenericMethod ("*disconnectNotify", "@brief Virtual method void QValidator::disconnectNotify(const QMetaMethod &signal)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_disconnectNotify_2394_0, &_call_cbs_disconnectNotify_2394_0);
  methods += new qt_gsi::GenericMethod ("*disconnectNotify", "@hide", false, &_init_cbs_disconnectNotify_2394_0, &_call_cbs_disconnectNotify_2394_0, &_set_callback_cbs_disconnectNotify_2394_0);
  methods += new qt_gsi::GenericMethod ("event", "@brief Virtual method bool QValidator::event(QEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_event_1217_0, &_call_cbs_event_1217_0);
  methods += new qt_gsi::GenericMethod ("event", "@hide", false, &_init_cbs_event_1217_0, &_call_cbs_event_1217_0, &_set_callback_cbs_event_1217_0);
  methods += new qt_gsi::GenericMethod ("eventFilter", "@brief Virtual method bool QValidator::eventFilter(QObject *, QEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_eventFilter_2411_0, &_call_cbs_eventFilter_2411_0);
  methods += new qt_gsi::GenericMethod ("eventFilter", "@hide", false, &_init_cbs_eventFilter_2411_0, &_call_cbs_eventFilter_2411_0, &_set_callback_cbs_eventFilter_2411_0);
  methods += new qt_gsi::GenericMethod ("fixup", "@brief Virtual method void QValidator::fixup(QString &)\nThis method can be reimplemented in a derived class.", true, &_init_cbs_fixup_c1330_0, &_call_cbs_fixup_c1330_0);
  methods += new qt_gsi::GenericMethod ("fixup", "@hide", true, &_init_cbs_fixup_c1330_0, &_call_cbs_fixup_c1330_0, &_set_callback_cbs_fixup_c1330_0);
  methods += new qt_gsi::GenericMethod ("*isSignalConnected", "@brief Method bool QValidator::isSignalConnected(const QMetaMethod &signal)\nThis method is protected and can only be called from inside a derived class.", true, &_init_fp_isSignalConnected_c2394, &_call_fp_isSignalConnected_c2394);
  methods += new qt_gsi::GenericMethod ("*receivers", "@brief Method int QValidator::receivers(const char *signal)\nThis method is protected and can only be called from inside a derived class.", true, &_init_fp_receivers_c1731, &_call_fp_receivers_c1731);
  methods += new qt_gsi::GenericMethod ("*sender", "@brief Method QObject *QValidator::sender()\nThis method is protected and can only be called from inside a derived class.", true, &_init_fp_sender_c0, &_call_fp_sender_c0);
  methods += new qt_gsi::GenericMethod ("*senderSignalIndex", "@brief Method int QValidator::senderSignalIndex()\nThis method is protected and can only be called from inside a derived class.", true, &_init_fp_senderSignalIndex_c0, &_call_fp_senderSignalIndex_c0);
  methods += new qt_gsi::GenericMethod ("*timerEvent", "@brief Virtual method void QValidator::timerEvent(QTimerEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_timerEvent_1730_0, &_call_cbs_timerEvent_1730_0);
  methods += new qt_gsi::GenericMethod ("*timerEvent", "@hide", false, &_init_cbs_timerEvent_1730_0, &_call_cbs_timerEvent_1730_0, &_set_callback_cbs_timerEvent_1730_0);
  methods += new qt_gsi::GenericMethod ("validate", "@brief Virtual method QValidator::State QValidator::validate(QString &, int &)\nThis method can be reimplemented in a derived class.", true, &_init_cbs_validate_c2171_0, &_call_cbs_validate_c2171_0);
  methods += new qt_gsi::GenericMethod ("validate", "@hide", true, &_init_cbs_validate_c2171_0, &_call_cbs_validate_c2171_0, &_set_callback_cbs_validate_c2171_0);
  return methods;
}

gsi::Class<QValidator_Adaptor> decl_QValidator_Adaptor (qtdecl_QValidator (), "QtGui", "QValidator",
  methods_QValidator_Adaptor (),
  "@qt\n@brief Binding of QValidator");

}


//  Implementation of the enum wrapper class for QValidator::State
namespace qt_gsi
{

static gsi::Enum<QValidator::State> decl_QValidator_State_Enum ("QtGui", "QValidator_State",
    gsi::enum_const ("Invalid", QValidator::Invalid, "@brief Enum constant QValidator::Invalid") +
    gsi::enum_const ("Intermediate", QValidator::Intermediate, "@brief Enum constant QValidator::Intermediate") +
    gsi::enum_const ("Acceptable", QValidator::Acceptable, "@brief Enum constant QValidator::Acceptable"),
  "@qt\n@brief This class represents the QValidator::State enum");

static gsi::QFlagsClass<QValidator::State > decl_QValidator_State_Enums ("QtGui", "QValidator_QFlags_State",
  "@qt\n@brief This class represents the QFlags<QValidator::State> flag set");

//  Inject the declarations into the parent
static gsi::ClassExt<QValidator> inject_QValidator_State_Enum_in_parent (decl_QValidator_State_Enum.defs ());
static gsi::ClassExt<QValidator> decl_QValidator_State_Enum_as_child (decl_QValidator_State_Enum, "State");
static gsi::ClassExt<QValidator> decl_QValidator_State_Enums_as_child (decl_QValidator_State_Enums, "QFlags_State");

}

