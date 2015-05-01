#include <QApplication>
#include <QWebView>
#include <QGraphicsWebView>
#include <QWebFrame>
#include <QUrl>
#include <QGraphicsView>
#include <QGraphicsScene>

int main(int argc, char** argv)
{

  QApplication app(argc, argv);
  QGraphicsView* view = new QGraphicsView(); 
  QGraphicsWebView qWebView;
  qWebView.setHtml("<html><head></head><body><p>welcome</p></body><script>function fun(){ alert('just like that');}</script></html>");
  QGraphicsScene* scene = new QGraphicsScene();
  view->setScene(scene); 
  scene->addItem(&qWebView);
  view->show();
  
  QWebPage* page = qWebView.page();
  page->mainFrame()->evaluateJavaScript("fun()"); 
  return app.exec();
}
