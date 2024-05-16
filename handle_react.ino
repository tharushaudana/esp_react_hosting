void handle_react(AsyncWebServer *server) {
  server->on("/*", HTTP_GET, [](AsyncWebServerRequest *req) {
    handle_react_reqs(req);
  });
}

void handle_react_reqs(AsyncWebServerRequest *req) {
  String full_route = req->url();

  if (full_route == "/") full_route = "/index.html";

  String type = full_route.substring(full_route.lastIndexOf("."));
  String mime = get_mime(type);

  //Serial.println("Full Route: " + full_route);

  if (mime != "") req->send(LittleFS, full_route, mime);
}

String get_mime(String type) {
  if (type == ".html") return "text/html";
  else if (type == ".js") return "text/javascript";
  else if (type == ".css") return "text/css";
  else if (type == ".ico") return "image/x-ico";
  else if (type == ".ttf" || type == ".otf" || type == ".woff") return "application/font-sfnt";
  else if (type == ".json") return "application/json";
  else if (type == ".xml") return "application/xml";
  else if (type == ".txt") return "text/plain";
  else if (type == ".jpg" || type == ".jpeg") return "image/jpeg";
  else if (type == ".png") return "image/png";
  else if (type == ".gif") return "image/gif";
  else if (type == ".svg") return "image/svg+xml";
  else if (type == ".webp") return "image/webp";
  else if (type == ".pdf") return "application/pdf";
  else if (type == ".zip") return "application/zip";
  else if (type == ".mp3") return "audio/mpeg";
  else if (type == ".mp4") return "video/mp4";
  else if (type == ".mpeg") return "video/mpeg";
  else if (type == ".webm") return "video/webm";
  return "";
}