#include "viewcontinentsframe.h"

ViewContinentsFrame::ViewContinentsFrame():
    Observer(),
    Gtk::Frame(),
    editor(),
    treeModel(),
    treeView() {
    // No realiza ninguna acciòn en principio.
}

ViewContinentsFrame::ViewContinentsFrame(
    const ReferenceCountPtr<Editor>& editor):
    Observer(),
    Gtk::Frame(),
    editor(editor),
    treeModel(),
    treeView() {
    // No realiza ninguna opciòn.
}

void ViewContinentsFrame::setEditor(const ReferenceCountPtr<Editor>& editor) {
    this->editor = editor;
}

ReferenceCountPtr<Editor> ViewContinentsFrame::getEditor() {
    return this->editor;
}

void ViewContinentsFrame::update(const Subject* subject) {
    // Aca actualizaria la lista de continentes.
}

ViewContinentsFrame::~ViewContinentsFrame() {
    // No realiza ninguna acciòn.
}

