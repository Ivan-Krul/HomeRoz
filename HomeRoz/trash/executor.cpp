#include "executor.h"
Executor::Executor(IInputModule* inputModule, IRenderModule* renderModule){
    mInputModule = inputModule;
    mRenderModule = renderModule;
}
void Executor::Input() {
    mInputModule->SenseKeyboard();
    mTable.SenseControl(mInputModule->GiveCommand());
    if (!mIsPrevInput == mIsInput)
        mInputModule->StartTypeInput(mTable.GiveInput());
    else if (mIsPrevInput == !mIsInput)
        mTable.CheckInput();
}
void Executor::Update() {
    mRenderModule->HearAwaitingInput(mTable.getIsInputAwait());
    mRenderModule->HearBufferingInput(mTable.getIsInputBufferise());
    mRenderModule->HearHWSelectMode(mTable.getIsSelectHW());
    mRenderModule->setHomeworkSelect(mTable.getHomeworkSelect());
    mRenderModule->setInputCurPos(mInputModule->getCurInput());
    mRenderModule->setInput(mInputModule->ReturnInput());
    mRenderModule->setIterHomework(mTable.getIterHomework());
    mRenderModule->setIterLesson(mTable.getIterLesson());
    mRenderModule->setLatestHomework(mTable.getLatestHomework());
    mRenderModule->setLineChoose(mTable.getLineChoose());
    auto cur_coord = mRenderModule->getCursorCoord();
    auto wnd = mRenderModule->Render();
    wnd.update(cur_coord);
}
