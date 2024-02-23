# Notes

- Node js is a javascript runtime build on google open source V8 javascript engine
- help to run javascript out side of browser

## NodeJs Pros

- Single Threaded, based on event driven, non-blocking I/O model
- perfect for building fast and scalable data-intensive apps
- javascript across entire stack fast and more effective development
- NPM : huge library of open source packages available for everyone for free

## Use of NodeJs

- API with database behind it
- Data Streaming
- real time chat application
- server-side web application

do not use node js in heavy servers side processing ie cpu intensive task instead use php ruby on rale or python

- if we write the 'node' in terminal then it open REPL: read evaluate print loop , .exit to exit repl, \_ is previous result, double tab will show you the global variable
- `node file.js` to run file

```js
// first program
const hello = "hello world";
console.log(hello);
```

```js
// require the module
const fs = require("fs");
```

- go to documentation if you need any help

## reading the file

```js
const fs = require("fs");
const data = fs.readFileSync("./txt/input.txt", "utf8");
console.log(data);
```

- use backtick for adding info inside the string

## writing into the file

```js
const fs = require("fs");
const data = fs.readFileSync("./txt/input.txt", "utf8");
console.log(data);

const text_out = `This is what we know about apple: ${data}.\nCreated on ${Date.now()}`;
console.log(text_out);
fs.writeFileSync("./txt/output.txt", text_out);
```

- synchronous code is also called as blocking the code because it run line by line
- solution to this problem is async-non-blocking code, we offload heavy-load basically work in background and when the work is done a callback function that is register before is called and handle the result
- thread is where our code is executed
- we can encounter callback hell while using async code solution is use of promise and async-await

## reading writing Non-blocking, Asynchronous way

```js
fs.readFile("./txt/start.txt", "utf8", (err, data) => {
  console.log(data);
  fs.writeFile("./txt/output.txt", `checking the ${data}`, "utf8", (err) => {
    console.log("your file has written");
  });
});
console.log("Reading the file.....");
```

## Creating the simple server

```js
const http = require("http");

const server = http.createServer((req, res) => {
  // call callback each time we hit the server
  res.end("Hello from the server");
});

server.listen(8000, "127.0.0.1", () => {
  console.log("Server started listening ");
});
```

## Routing

- implementing different action for different URL's

```js
const http = require("http");
const url = require("url");

const server = http.createServer((req, res) => {
  // call callback each time we hit the server
  const path = req.url;
  if (path === "/overview") {
    res.end("This is overview");
  } else if (path === "/product") {
    res.end("Your are in product section");
  } else {
    res.writeHead(404, {
      "Content-type": "text/html",
      "my-own-header": "deep",
    });
    res.end("Url does not exist");
  }
});

server.listen(8000, "127.0.0.1", () => {
  console.log("Server started listening ");
});
```

## API

- service from where we can request the data

```js
const http = require("http");
const url = require("url");

const server = http.createServer((req, res) => {
  // call callback each time we hit the server
  const path = req.url;
  if (path === "/overview") {
    res.end("This is overview");
  } else if (path === "/product") {
    res.end("Your are in product section");
  } else if (path === "/api") {
    fs.readFile("./dev-data/data.json", "utf-8", (err, data) => {
      const json = JSON.parse(data);
      console.log(json);
      res.writeHead(200, {
        "Content-type": "application/json",
      });
      res.end(data);
    });
  } else {
    res.writeHead(404, {
      "Content-type": "text/html",
      "my-own-header": "deep",
    });
    res.end("Url does not exist");
  }
});

server.listen(8000, "127.0.0.1", () => {
  console.log("Server started listening ");
});
```

- url.parse(req.url,true) to get parameter
- every single file in node js is module
- function without name is called anonymous function
- npm: node package manager
- `npm init` before starting the project which create package.json file
- `npm install package-name` : install package
- to run local dependency we use script to run it we cannot run directly
- to run script '`npm run script-name`'
- two type of dependency (regular and developer)
- .prettierrc for prettier configuration file

```js
const fs = require("fs");
const http = require("http");
const url = require("url");
const slugify = require("slugify");
const replaceTemplate = require("./modules/replaceTemplate");

/////////////////////////////////
// FILES

// Blocking, synchronous way
// const textIn = fs.readFileSync('./txt/input.txt', 'utf-8');
// console.log(textIn);
// const textOut = `This is what we know about the avocado: ${textIn}.\nCreated on ${Date.now()}`;
// fs.writeFileSync('./txt/output.txt', textOut);
// console.log('File written!');

// Non-blocking, asynchronous way
// fs.readFile('./txt/start.txt', 'utf-8', (err, data1) => {
//   if (err) return console.log('ERROR! 💥');

//   fs.readFile(`./txt/${data1}.txt`, 'utf-8', (err, data2) => {
//     console.log(data2);
//     fs.readFile('./txt/append.txt', 'utf-8', (err, data3) => {
//       console.log(data3);

//       fs.writeFile('./txt/final.txt', `${data2}\n${data3}`, 'utf-8', err => {
//         console.log('Your file has been written 😁');
//       })
//     });
//   });
// });
// console.log('Will read file!');

/////////////////////////////////
// SERVER
const tempOverview = fs.readFileSync(
  `${__dirname}/templates/template-overview.html`,
  "utf-8"
);
const tempCard = fs.readFileSync(
  `${__dirname}/templates/template-card.html`,
  "utf-8"
);
const tempProduct = fs.readFileSync(
  `${__dirname}/templates/template-product.html`,
  "utf-8"
);

const data = fs.readFileSync(`${__dirname}/dev-data/data.json`, "utf-8");
const dataObj = JSON.parse(data);

const slugs = dataObj.map((el) => slugify(el.productName, { lower: true }));
console.log(slugs);

const server = http.createServer((req, res) => {
  const { query, pathname } = url.parse(req.url, true);

  // Overview page
  if (pathname === "/" || pathname === "/overview") {
    res.writeHead(200, {
      "Content-type": "text/html",
    });

    const cardsHtml = dataObj
      .map((el) => replaceTemplate(tempCard, el))
      .join("");
    const output = tempOverview.replace("{%PRODUCT_CARDS%}", cardsHtml);
    res.end(output);

    // Product page
  } else if (pathname === "/product") {
    res.writeHead(200, {
      "Content-type": "text/html",
    });
    const product = dataObj[query.id];
    const output = replaceTemplate(tempProduct, product);
    res.end(output);

    // API
  } else if (pathname === "/api") {
    res.writeHead(200, {
      "Content-type": "application/json",
    });
    res.end(data);

    // Not found
  } else {
    res.writeHead(404, {
      "Content-type": "text/html",
      "my-own-header": "hello-world",
    });
    res.end("<h1>Page not found!</h1>");
  }
});

server.listen(8000, "127.0.0.1", () => {
  console.log("Listening to requests on port 8000");
});
```

- client send request to server and server send the response to client
- http: hyper text transport protocol
- https is encrypted with SSL and TLS

## Node Architecture behind the scenes

- node js have several dependency two of them are V8 engine and libuv
- V8 convert javascript code to machine code
- libuv is open source library which focus on asynchronous I/O give nodejs access to the underlying os, networking, file etc along with even loop and thread pool
- libuv is completely written in C++
- there are many more library on which node js depends OpenSSL for cryptography, zlib for compression
- process in thread: Init the program => Execute Top-level code => Require Module => Register the call-back => start event loop
- thread pool provide four additional thread for more heavy task and we can configure up-to 128 threads
- event loop offload heavy task to thread pool
- in event loop all non-top level code is executed (inside callback function code)
- Event Driven Architecture: Events are emitted => Event Loop pickup them => callback are called
- Event loop have multiple phase and each phase have callback queue
- first phase Expired timer callback
- second phase I/O polling and callback (networking and file access)
- third phase setImmediate callback
- fourth close Callback
- beside this four there are more process.NEXTTICK() queue and other microTask queue (to resolve promise) these two queue can executed just after any of phase
- How to avoid blocking:

1. Don't use sync version of function
2. Don't perform complex calculation (loop inside loop)
3. Be careful with json with large size
4. Don't use complex regular expression

```js
const fs = require("fs");
const crypto = require("crypto");

const start = Date.now();
process.env.UV_THREADPOOL_SIZE = 4;

setTimeout(() => console.log("Timer 1 finished"), 0);
setImmediate(() => console.log("Immediate 1 finished"));

fs.readFile("test-file.txt", () => {
  console.log("I/O finished");
  console.log("----------------");

  setTimeout(() => console.log("Timer 2 finished"), 0);
  setTimeout(() => console.log("Timer 3 finished"), 3000);
  setImmediate(() => console.log("Immediate 2 finished"));

  process.nextTick(() => console.log("Process.nextTick"));

  crypto.pbkdf2Sync("password", "salt", 100000, 1024, "sha512");
  console.log(Date.now() - start, "Password encrypted");

  crypto.pbkdf2Sync("password", "salt", 100000, 1024, "sha512");
  console.log(Date.now() - start, "Password encrypted");

  crypto.pbkdf2Sync("password", "salt", 100000, 1024, "sha512");
  console.log(Date.now() - start, "Password encrypted");

  crypto.pbkdf2Sync("password", "salt", 100000, 1024, "sha512");
  console.log(Date.now() - start, "Password encrypted");
});

console.log("Hello from the top-level code");
```

- we have event emitter which emits event then this event are pickup by event listeners and fire the callback function

```js
const server = http.createServer();
server.on("request", (req, res) => {
  console.log("Request Received");
  res.end("Hello");
});
```

- by calling super class we get the access to all method of super class

```js
const EventEmitter = require("events");
const http = require("http");

class Sales extends EventEmitter {
  constructor() {
    super();
  }
}

const myEmitter = new Sales();

myEmitter.on("newSale", () => {
  console.log("There was a new sale!");
});

myEmitter.on("newSale", () => {
  console.log("Costumer name: Jonas");
});

myEmitter.on("newSale", (stock) => {
  console.log(`There are now ${stock} items left in stock.`);
});

myEmitter.emit("newSale", 9);

//////////////////

const server = http.createServer();

server.on("request", (req, res) => {
  console.log("Request received!");
  console.log(req.url);
  res.end("Request received");
});

server.on("request", (req, res) => {
  console.log("Another request 😀");
});

server.on("close", () => {
  console.log("Server closed");
});

server.listen(8000, "127.0.0.1", () => {
  console.log("Waiting for requests...");
});
```

## Streams

- use to process (read and write) the data piece by piece without completing whole read operation and therefore without keeping all the data in memory
- stream are the instances of `EventEmitter` Class
- back pressure happens when the response cannot send data nearly as fast as it is receiving it solution to this problem is solution 3 ie pipe method

```js
const fs = require("fs");
const server = require("http").createServer();

server.on("request", (req, res) => {
  // Solution 1
  // fs.readFile("test-file.txt", (err, data) => {
  //   if (err) console.log(err);
  //   res.end(data);
  // });

  // Solution 2: Streams
  // const readable = fs.createReadStream("test-file.txt");
  // readable.on("data", chunk => {
  //   res.write(chunk);
  // });
  // readable.on("end", () => {
  //   res.end();
  // });
  // readable.on("error", err => {
  //   console.log(err);
  //   res.statusCode = 500;
  //   res.end("File not found!");
  // });

  // Solution 3
  const readable = fs.createReadStream("test-file.txt");
  readable.pipe(res);
  // readableSource.pipe(writeableDest)
});

server.listen(8000, "127.0.0.1", () => {
  console.log("Listening...");
});
```

## Promise and Async/Await

- example of callback hell

```js
const fs = require("fs");
const superagent = require("superagent");

fs.readFile("./data", (err, data) => {
  console.log(`Breed of dog is: ${data}`);
  superagent
    .get(`https://dog.ceo/api/breed/${data}/images/randoms`)
    .end((err, data) => {
      if (err) return console.log(err.message);
      console.log(res.body.message);
      fs.writeFile("dog-image.txt", res.body.message, (err) => {
        console.log("Image have been saved ");
      });
    });
});
```

- promise : we will get data back in future
- resolve promise: when promise get back after getting data
- chain .then method which return promise

```js
const fs = require("fs");
const superagent = require("superagent");

const readFilePro = (file) => {
  return new Promise((resolve, reject) => {
    fs.readFile(file, (err, data) => {
      if (err) reject("I could not find that file 😢");
      resolve(data);
    });
  });
};

const writeFilePro = (file, data) => {
  return new Promise((resolve, reject) => {
    fs.writeFile(file, data, (err) => {
      if (err) reject("Could not write file 😢");
      resolve("success");
    });
  });
};

const getDogPic = async () => {
  try {
    const data = await readFilePro(`${__dirname}/dog.txt`);
    console.log(`Breed: ${data}`);

    const res1Pro = superagent.get(
      `https://dog.ceo/api/breed/${data}/images/random`
    );
    const res2Pro = superagent.get(
      `https://dog.ceo/api/breed/${data}/images/random`
    );
    const res3Pro = superagent.get(
      `https://dog.ceo/api/breed/${data}/images/random`
    );
    const all = await Promise.all([res1Pro, res2Pro, res3Pro]);
    const img = all.map((el) => el.body.message);
    console.log(img);

    await writeFilePro("dog-img.txt", img.join("\n"));
    console.log("Random dog image saved to file!");
  } catch (err) {
    console.log(err);

    throw err;
  }
  return "2: READY 🐶";
};

(async () => {
  try {
    console.log("1: Will get dog pics!");
    const x = await getDogPic();
    console.log(x);
    console.log("3: Done getting dog pics!");
  } catch (err) {
    console.log("ERROR 💥");
  }
})();

/*
console.log('1: Will get dog pics!');
getDogPic()
  .then(x => {
    console.log(x);
    console.log('3: Done getting dog pics!');
  })
  .catch(err => {
    console.log('ERROR 💥');
  });
*/
/*
readFilePro(`${__dirname}/dog.txt`)
  .then(data => {
    console.log(`Breed: ${data}`);
    return superagent.get(`https://dog.ceo/api/breed/${data}/images/random`);
  })
  .then(res => {
    console.log(res.body.message);
    return writeFilePro('dog-img.txt', res.body.message);
  })
  .then(() => {
    console.log('Random dog image saved to file!');
  })
  .catch(err => {
    console.log(err);
  });
*/
```

- we should to throw an error if we want to mark it rejected

## Express

- it is an minimal node.js framework for high level of Abstraction
- written 100% in nodejs code
- help to develop application very fast
- make easier to organize application in MVC architecture

```js
const express = require("express");
const app = express();
const port = 3000;

app.get("/", (req, res) => {
  res.status(200);
  res.send("Hello, world!");
});

app.listen(port, () => {
  console.log("Server listening on port 3000");
});
```

- api: application programming Interface ie a piece of software that is used by another piece of software, in order to allow application to talk to each other
- REST Architecture : representational State Transfer, make api easy to consume
- principle of REST:

1. separate API into logical Resources
2. Expose structured resource based URLs
3. use HTTP method
4. Send Data as JSON
5. must be stateless

- resource is object or representation of something which has data associated with it. Any information that can be named can be resource
- different action should have different endpoint
- Endpoint should contain only resources and use http method for action
- use resource name in plural
- GET read, POST Create , DELETE Delete, PUT or PATCH update
- CRUD : create, read, update, and delete
- wrapping the data into additional objects is called enveloping
- JSend is use to send the data in formatted way
- stateless mean by all actions should be handled by Client mean by each request must contain all necessary information to process the request, should no need to remember previous request
- `js  (req, res) => {}` is called route handlers
- by default express does not add body data we need to use middleware
- app.use(fun) to use middleware

```js
// way to read parameters or variables
app.get("/api/v1/tours/:id/:x?", (req, res) => {
  console.log(req.params);
});
```

- above x is optional parameter
- below are same but easy .route is more easy to read

```js
app.get("/api/v1/tours", fun);
app.route("api/v1/tours").get(fun).post(fun2);
```

- middleware manipulate the request response cycle
- all middleware together is called middleware stack and order matter in code

```js
const tourRouter = express.Router();

tourRouter.route("/").get(getALLTours);
app.use("/api/v1/tours", tourRouter);
```

- above is best way to route multiple resources
- tourRouter is actually is a middleware

```js
router.param("id", tourController.checkID);
```

- above is param middleware which only run when some parameter present in route

```js
router.get(middleware, handlerFunction);
```

- above if we want to executer the middleware before the handler function
- app.use(express.static('./public')) to serve the static file in public directory

## MongoDB

- NOsql database
- each database contain different collections analogous to table
- each collection can have one or more documents analogous to row
- thus document based database
- scalable
- flexibility
- performance
- free and open source
- Use BSON similar to JSON but typed for data format
- embedded documents also called as De-normalizing
- mongoose is object data model library for mongoDB and NodeJs, a higher level of abstraction
- Mongoose schema : Where we model our data, by describing the structure of the data, default values and validation
- mongoose model: a wrapper for the schema, providing an interface to database for CRUD operations

## Errors

- operational error: Problem that we can predict will happen at some point, so we just need to handle them in advance
- programming error: Problem that developers introduced into our code

```js
const db = process.env.CONNECT.replace("<%PASSWORD%>", process.env.DB_PASSWORD);
// console.log(db);
mongoose.connect(db).then((connection) => {
  // console.log(connection);
  console.log("Database connection established");
});

const tourSchema = new mongoose.Schema({
  name: {
    type: String,
    required: [true, "tour must have a name"],
    // above is called validator
    unique: true,
  },
  rating: {
    type: Number,
    default: 4.5,
  },
  price: Number,
});
const Tour = mongoose.model("Tour", tourSchema);
```

- mongoose is higher level of abstraction on mongoDB allow us to fast development
- mongoose Schema : describe the structure of data
- mongoose Model : a wrapper for schema
- MVC : model view controller , model have business logic, view have presentation logic and controller have Application logic
- make easier to maintain and scale application using above architecture

## JWT Authentication

- Here are steps :

1. Post request to server /login {email,password}
2. if User and password create unique JWT Token
3. send response back to client along with token
4. client will store token in cookies or local-storage
5. while accessing any route we use pass jwt token as well
6. If valid JWT token the allow access
7. return protected data

### signature working

```js

Header + payload ---------> JWT---> CLIENT
        ^-----Signature------^
Secret-------^




CLIENT ---> JWT ---> Header + payload ---> TEST_SIGNATURE
                                secret-------^

                            Compare Original signature and test signature

```

## Security Measures

- Always use https
- Deny access to JWT after password change
- don't send error details to client
- prevent Cross-site requests Forgery (csurf package)
- confirm user email after first creation of account
- implement 2FA

### Avoid Brute Force

- Use bcrypt (to make login request slow)
- implement rate limiter (express-rate-limit)
- implement max login attempts

### Cross Site Scripting (XSS)

- store JWT in HTTPOnly Cookies
- sanitize user input
- set special HTTP header (helmet package)

### DOS attacks

- implement rate limiter
- limit body payload (body-parser)
- Avoid evil regular expressions
