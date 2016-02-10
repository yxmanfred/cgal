// Copyright (c) 2015  GeometryFactory SARL (France).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; either version 3 of the License,
// or (at your option) any later version.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL$
// $Id$
// 
//
// Author(s)     : Laurent Rineau and Maxime Gimeno
#ifndef CGAL_QT_CREATE_OPENGL_CONTEXT_H
#define CGAL_QT_CREATE_OPENGL_CONTEXT_H
#include <QOpenGLContext>
#include <QGLContext>
namespace CGAL{
namespace Qt{
inline QGLContext* createOpenGLContext(QObject* parent)
{
    QOpenGLContext *context = new QOpenGLContext(parent);
    QSurfaceFormat format;
    format.setVersion(2,1);
    format.setProfile(QSurfaceFormat::CompatibilityProfile);
    context->setFormat(format);
    QGLContext *result = QGLContext::fromOpenGLContext(context);
    result->create();
    return result;
}

inline QGLContext* createOpenGLMSAAContext(QObject* parent)
{
    QOpenGLContext *context = new QOpenGLContext(parent);
    QSurfaceFormat format;
    format.setVersion(2,1);
    format.setProfile(QSurfaceFormat::CompatibilityProfile);
    format.setSamples(16);
    context->setFormat(format);
    QGLContext *result = QGLContext::fromOpenGLContext(context);
    result->create();
    return result;
}
} // namespace Qt
} // namespace CGAL
#endif
