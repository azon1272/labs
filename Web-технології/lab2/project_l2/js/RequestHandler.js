function RequestHandler(cfg) {
	this.cfg = cfg;
	this.xmlHttpReq = null;
}


RequestHandler.prototype.getXmlHttpRequest = function (){
	try {
		return new ActiveXObject("Msxml2.XMLHTTP");
	} catch (e) {
		try {
			return new ActiveXObject("Microsoft.XMLHTTP");
		} catch (ee) {
		}
	}
	if (typeof XMLHttpRequest!='undefined') {
		return new XMLHttpRequest();
	}
}

// Получить данные с url и вызывать cb - коллбэк c ответом сервера 
RequestHandler.prototype.getUrl = function(url, params, cb) { 
	this.xmlHttpReq = this.getXmlHttpRequest();
	// IE кэширует XMLHttpRequest запросы, так что добавляем случайный параметр к URL
	var xhr = this.xmlHttpReq;	
	xhr.open("GET", url, true); // asynchronous call
	xhr.setRequestHeader("Content-Type", "application/json;charset=UTF-8");
    xhr.onreadystatechange = this.handleRequest(cb);
    // xhr.send(JSON.stringify(params));
    xhr.send();
}
//cb {function}-- callback function
RequestHandler.prototype.handleRequest = function(cb) {
	var xhr = this.xmlHttpReq;
	if (xhr.readyState == 4) {
		cb(
			xhr.status, 
			xhr.getAllResponseHeaders(), 
			xhr.responseText
		);
	}
}
