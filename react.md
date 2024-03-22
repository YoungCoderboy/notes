# React Fundamentals

- A javascript library for building user interface
- developed by facebook
- when it comes to react it is all about components
- your website can have as many component you like but there is always one root component
- you can build independent component and change according to state but it will not affect app
- this provide reusability of components and speed
- redux: most popular state management library
- React apps are made out of components. A component is a piece of the UI (user interface) that has its own logic and appearance. A component can be as small as a button, or as large as an entire page.
- tools: vite, create react app

- JSX is stricter than HTML. You have to close tags like <br />. Your component also can’t return multiple JSX tags. You have to wrap them into a shared parent, like a <div>...</div> or an empty <>...</> wrapper:
- `npx create-react-app app-name`
- `npx create-react-app ./` make current folder as app

#### Folder Structure

- node_modules
  Contains all dependencies required by the app. Main dependencies also listed in package.json

- public
  Contains static assets including index.html (page template)
  - index.html
    - title
    - fonts
    - css
    - favicon
    - id="root" - our entire app
- src
  In simplest form it's the brain of our app. This is where we will do all of our work. src/index.js is the JavaScript entry point.
- .gitignore
  Specifies which files source control (Git) should ignore

- package.json
  Every Node.js project has a package.json and it contains info about our project, for example list of dependencies and scripts

- package-lock.json
  A snapshot of the entire dependency tree

- README
  The markdown file where you can share more info about the project for example build instructions and summary

#### First Component

- All events propagate in React except onScroll, which only works on the JSX tag you attach it to.

```js
function Greeting() {
  return <h2>My First Component</h2>;
}

// arrow function also works

const Greeting = () => {
  return <h2>My First Component</h2>;
};
```

- starts with capital letter
- must return JSX (html)
- always close tag <Greeting/>

##### Typical Component

```js
// imports or logic

const Greeting = () => {
  return <h2>My First Component</h2>;
};
export default Greeting;
```

##### Root Component (only one)

index.js

```js
import React from "react";
import ReactDOM from "react-dom/client";

function Greeting() {
  return <h2>My First Component</h2>;
}

const root = ReactDOM.createRoot(document.getElementById("root"));

root.render(<Greeting />);
```

#### Possible Bug

If for some reason you still have this error in the terminal

```
Module not found: Error: Can't resolve 'path/index.js'
```

Just restart the server

- CTRL + C (stop the server)
- "npm start" (start the dev server)

#### Extensions and settings.json

- Auto Rename Tag
- Highlight Matching Tag
  - customize in settings.json
- Prettier
  - format on save
  - format on paste
  - Default Formatter (Prettier - Code formatter)

settings.json

```json
  "editor.formatOnPaste": true,
  "editor.formatOnSave": true,
  "editor.defaultFormatter": "esbenp.prettier-vscode",
    "prettier.singleQuote": true,
    "prettier.semi": false,
```

- Emmet

settings.json

```json
"emmet.includeLanguages": {
    "javascript": "javascriptreact"
  },
```

- ES7 Snippets
  - rafce (arrow func with export)
  - rfce (regular func with export )
  - same as the file name
  - react auto import
    - uncheck
    - React Snippets › Settings: Import React On Top

#### First Component in Detail

- capital letter
- must return something
- JSX syntax (return html)
  - to make our lives easier
  - calling function under the hood

index.js

```js
const Greeting = () => {
  return React.createElement("h2", {}, "hello world");
};
```

```js
function Greeting() {
  return (
    <div>
      <h2>hello world</h2>
    </div>
  );
}

const Greeting = () => {
  return React.createElement(
    "div",
    {},
    React.createElement("h2", {}, "hello world")
  );
};
```

#### JSX Rules

- return single element (one parent element)

  - semantics section/article
  - Fragment - let's us group elements without adding extra nodes

```js
return <React.Fragment>...rest of the return</React.Fragment>;

// shorthand

return <>...rest of the return</>;
```

- camelCase property naming convention

```js
return (
  <div tabIndex={1}>
    <button onClick={myFunction}>click me</button>
    <label htmlFor='name'>Name</label>
    <input readOnly={true} id='name' />
  </div>
)
// in html
<div tabindex="1">
    <button onclick="myFunction()">click me</button>
    <label for='name'>Name</label>
    <input readonly id='name' />
</div>
```

- className instead of class

```js
return <div className="someValue">hello</div>;
```

- close every element

```js
return <img />;
// or
return <input />;
```

- formatting
  - opening tag in the same line as return or ()

```js
function Greeting() {
  return (
    <>
      <div className="someValue">
        <h3>hello people</h3>
        <ul>
          <li>
            <a href="#">hello world</a>
          </li>
        </ul>
      </div>
      <h2>hello world</h2>
      <input type="text" name="" id="" />
    </>
  );
}
```

#### Nest Components

```js
function Greeting() {
  return (
    <div>
      <Person />
      <Message />
    </div>
  );
}

const Person = () => <h2>john doe</h2>;
const Message = () => {
  return <p>this is my message</p>;
};
```

#### React Developer Tools

- top right corner
- more tools/extensions
- open chrome web store

#### Book List

- setup structure

```js
import React from "react";
import ReactDOM from "react-dom/client";

function BookList() {
  return (
    <section>
      <Book />
      <Book />
      <Book />
      <Book />
    </section>
  );
}

const Book = () => {
  return (
    <article>
      <Image />
      <Title />
      <Author />
    </article>
  );
};

const Image = () => <h2>image placeholder</h2>;
const Title = () => {
  return <h2>Book Title</h2>;
};
const Author = () => <h4>Author</h4>;

const root = ReactDOM.createRoot(document.getElementById("root"));

root.render(<BookList />);
```

```js
import React from "react";
import ReactDOM from "react-dom/client";

function BookList() {
  return (
    <section>
      <Book />
      <Book />
      <Book />
      <Book />
    </section>
  );
}

const Book = () => {
  return (
    <article className="book">
      <Image />
      <Title />
      <Author />
    </article>
  );
};

const Image = () => (
  <img
    src="https://images-na.ssl-images-amazon.com/images/I/71m+Qtq+HrL._AC_UL900_SR900,600_.jpg"
    alt="Interesting Facts For Curious Minds"
  />
);
const Title = () => {
  return <h2>Interesting Facts For Curious Minds</h2>;
};
const Author = () => <h4>Jordan Moore </h4>;

const root = ReactDOM.createRoot(document.getElementById("root"));

root.render(<BookList />);
```

#### CSS

- create index.css in src

```css
* {
  margin: 0;
  padding: 0;
  box-sizing: border-box;
}

body {
  font-family: system-ui, -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto,
    Oxygen, Ubuntu, Cantarell, "Open Sans", "Helvetica Neue", sans-serif;
  background: #f1f5f8;
  color: #222;
}
```

- import file and add classes

```js
import "./index.css";

function BookList() {
  return (
    <section className="booklist">
      <Book />
      <Book />
      <Book />
      <Book />
    </section>
  );
}

const Book = () => {
  return (
    <article className="book">
      <Image />
      <Title />
      <Author />
    </article>
  );
};
```

- you can also do this below:

```js
import React from "react";
import ReactDOM from "react-dom/client";
import "./styles/index.css";
import "./styles/test.css";
const Greeting = () => {
  return <h1>hello world</h1>;
};
const root = ReactDOM.createRoot(document.getElementById("root"));
root.render(<Greeting />);
```

- complete css

```css
.booklist {
  width: 90vw;
  max-width: 1170px;
  margin: 5rem auto;
  display: grid;
  gap: 2rem;
}

@media screen and (min-width: 768px) {
  .booklist {
    grid-template-columns: repeat(3, 1fr);
  }
}
.book {
  background: #fff;
  border-radius: 1rem;
  padding: 2rem;
  text-align: center;
}
.book img {
  width: 100%;
  object-fit: cover;
}
.book h2 {
  margin-top: 1rem;
  font-size: 1rem;
}
```

#### Local Images (Public Folder)

- external images (hosted on different server) - just need an url
- local images (public folder) - less performant
- local images (src folder) - better solution for assets,
  since under the hood they get optimized.

- save image (Save Image As....)
- create images folder in public
- copy/paste image
- rename (optional)
- replace url in the src - './images/imageName.extension'
- './' because assets are on the same server

```js
const Image = () => (
  <img src="./images/book-1.jpg" alt="Interesting Facts For Curious Minds" />
);
```

- whatever assets we place in public - instantly available
- domain(localhost)/asset

#### JSX - CSS (inline styles)

- style prop
- {} in JSX means going back to JS Land
- value is an object with key/value pairs - capitalized and with ''

```js
const Author = () => (
  <h4 style={{ color: "#617d98", fontSize: "0.75rem", marginTop: "0.5rem" }}>
    Jordan Moore
  </h4>
);
```

- css rules still apply (inline vs external css)

```css
.book h4 {
  /* won't work */
  color: red;
  /* will work */
  letter-spacing: 2px;
}
```

- external libraries use inline css,
  so if you want to make some changes,
  reference the library docs and elements tab

- alternative option

```js
const Author = () => {
  const inlineHeadingStyles = {
    color: "#617d98",
    fontSize: "0.75rem",
    marginTop: "0.5rem",
  };
  return <h4 style={inlineHeadingStyles}>Jordan Moore </h4>;
};
```

- FOR THE MOST PART, MULTIPLE APPROACHES AVAILABLE !!!
- AS LONG AS THE RESULT IS THE SAME, REALLY COMES DOWN TO PREFERENCE !!!!

#### JSX - Javascript

- refactor to single book component (personal preference)
- remove inline css

```js
const Book = () => {
  return (
    <article className="book">
      <img
        src="./images/book-1.jpg"
        alt="Interesting Facts For Curious Minds"
      />
      <h2>Interesting Facts For Curious Minds</h2>
      <h4>Jordan Moore </h4>
    </article>
  );
};
```

```css
.book h4 {
  color: #617d98;
  font-size: 0.75rem;
  margin-top: 0.5rem;
  letter-spacing: 2px;
}
```

- {} in JSX means going back to JS Land
- value inside must be an expression (return value),
  can't be a statement

```js
const author = "Jordan Moore";
const Book = () => {
  const title = "Interesting Facts For Curious Mindssssss";
  return (
    <article className="book">
      <img
        src="./images/book-1.jpg"
        alt="Interesting Facts For Curious Minds"
      />
      <h2>{title}</h2>

      <h4>{author.toUpperCase()} </h4>
      {/* <p>{let x = 6}</p> */}
      <p>{6 + 6}</p>
    </article>
  );
};
```

- toggle line comment Edit/Toggle Line Comment

#### Props - Initial Setup

- refactor/clean up

```js
const author = "Jordan Moore";
const title = "Interesting Facts For Curious Minds";
const img = "./images/book-1.jpg";

function BookList() {
  return (
    <section className="booklist">
      <Book />
      <Book />
    </section>
  );
}
const Book = () => {
  return (
    <article className="book">
      <img src={img} alt={title} />
      <h2>{title}</h2>
      <h4>{author} </h4>
    </article>
  );
};
```

```js
// parameters
const someFunc = (param1, param2) => {
  console.log(param1, param2);
};
// arguments
someFunc("job", "developer");
```

```js
const Book = (props) => {
  console.log(props);
  return (
    <article className="book">
      <img src={img} alt={title} />
      <h2>{title}</h2>
      <h4>{author} </h4>
      {console.log(props)}
    </article>
  );
};
```

- props object, convention to call props, 'shakeAndBake' is an excellent alternative

- pass as key/value pairs
- if the prop exists it will return value, otherwise no value

```js
function BookList() {
  return (
    <section className="booklist">
      <Book job="developer" />
      <Book title="random title" number={22} />
    </section>
  );
}
const Book = (props) => {
  console.log(props);
  return (
    <article className="book">
      <img src={img} alt={title} />
      <h2>{title}</h2>
      <h4>{author} </h4>
      <p>{props.job}</p>
      <p>{props.title}</p>
      <p>{props.number}</p>
    </article>
  );
};
```

```js
function BookList() {
  return (
    <section className="booklist">
      <Book author={author} title={title} img={img} />
      <Book title={title} img={img} />
    </section>
  );
}
const Book = (props) => {
  console.log(props);
  return (
    <article className="book">
      <img src={props.img} alt={props.title} />
      <h2>{props.title}</h2>
      <h4>{props.author} </h4>
    </article>
  );
};
```

#### Props - Somewhat Dynamic Setup

- setup an object
- refactor vars to properties
- copy/paste and rename
- get values for second book
- setup props

```js
const firstBook = {
  author: "Jordan Moore",
  title: "Interesting Facts For Curious Minds",
  img: "./images/book-1.jpg",
};
const secondBook = {
  author: "James Clear",
  title: "Atomic Habits",
  img: "https://images-na.ssl-images-amazon.com/images/I/81wgcld4wxL._AC_UL900_SR900,600_.jpg",
};

function BookList() {
  return (
    <section className="booklist">
      <Book
        author={firstBook.author}
        title={firstBook.title}
        img={firstBook.img}
      />
      <Book
        author={secondBook.author}
        title={secondBook.title}
        img={secondBook.img}
      />
    </section>
  );
}
const Book = (props) => {
  console.log(props);
  return (
    <article className="book">
      <img src={props.img} alt={props.title} />
      <h2>{props.title}</h2>
      <h4>{props.author} </h4>
    </article>
  );
};
```

#### Access Props - Multiple Approaches

- there is no right or wrong - again preference !!!

- Destructuring (object)
  [JS Nuggets - Destructuring (object)](https://www.youtube.com/watch?v=i4vhNKihfto&list=PLnHJACx3NwAfRUcuKaYhZ6T5NRIpzgNGJ&index=8&t=1s)

- destructuring in Vanilla JS
- saves time/typing
- pull out the properties
- don't need to reference object anymore

```js
const someObject = {
  name: "john",
  job: "developer",
  location: "florida",
};

console.log(someObject.name);
const { name, job } = someObject;
console.log(job);
```

- no need for all the props.propName
- destructure inside component

```js
const Book = (props) => {
  const { img, title, author } = props;
  return (
    <article className="book">
      <img src={img} alt={title} />
      <h2>{title}</h2>
      <h4>{author} </h4>
    </article>
  );
};
```

- destructure in function parameters (in our case props)
- if you have console.log(props) - it won't be defined

```js
const Book = ({ img, title, author }) => {
  return (
    <article className="book">
      <img src={img} alt={title} />
      <h2>{title}</h2>
      <h4>{author} </h4>
    </article>
  );
};
```

#### Children Prop

- if we want to add some html at certain component then use children props
- here p and button is added to only book one
- everything we render between component tags
- during the course we will mostly use it Context API
- special prop, has to be "children"
- can place anywhere in JSX

```js
function BookList() {
  return (
    <section className="booklist">
      <Book
        author={firstBook.author}
        title={firstBook.title}
        img={firstBook.img}
      >
        <p>
          Lorem ipsum dolor, sit amet consectetur adipisicing elit. Itaque
          repudiandae inventore eos qui animi sed iusto alias eius ea sapiente.
        </p>
        <button>click me</button>
      </Book>
      <Book
        author={secondBook.author}
        title={secondBook.title}
        img={secondBook.img}
      />
    </section>
  );
}

const Book = ({ img, title, author, children }) => {
  // rest of the logic
};
const Book = (props) => {
  const { img, title, author, children } = props;
  console.log(props);
  return (
    <article className="book">
      <img src={img} alt={title} />
      <h2>{title}</h2>
      <h4>{author} </h4>
      {children}
    </article>
  );
};
```

- optional

```css
@media screen and (min-width: 768px) {
  .booklist {
    grid-template-columns: repeat(3, 1fr);
    align-items: start;
  }
}
.book p {
  margin: 1rem 0 0.5rem;
}
```

#### Simple List

- [Javascript Nuggets - Map ](https://www.youtube.com/watch?v=80KX6aD9R7M&list=PLnHJACx3NwAfRUcuKaYhZ6T5NRIpzgNGJ&index=1)

- refactor
- we can render the array in jsx but not object

```js
const books = [
  {
    author: "Jordan Moore",
    title: "Interesting Facts For Curious Minds",
    img: "./images/book-1.jpg",
  },
  {
    author: "James Clear",
    title: "Atomic Habits",
    img: "https://images-na.ssl-images-amazon.com/images/I/81wgcld4wxL._AC_UL900_SR900,600_.jpg",
  },
];

function BookList() {
  return <section className="booklist"></section>;
}

const Book = (props) => {
  const { img, title, author } = props;

  return (
    <article className="book">
      <img src={img} alt={title} />
      <h2>{title}</h2>
      <h4>{author} </h4>
    </article>
  );
};
```

- can't render objects in React

```js
function BookList() {
  return <section className="booklist">{books}</section>;
}
```

- map - creates a new array from calling a function for every array element.

```js
const names = ["john", "peter", "susan"];
const newNames = names.map((name) => {
  console.log(name);
  return <h1>{name}</h1>;
});

function BookList() {
  return <section className="booklist">{newNames}</section>;
}
```

#### Proper List

- remove names and newNames

```js
function BookList() {
  return (
    <section className="booklist">
      {books.map((book) => {
        console.log(book);

        // return 'hello';
        return (
          <div>
            <h2>{book.title}</h2>
          </div>
        );
      })}
    </section>
  );
}
```

- render component
- pass properties one by one

```js
function BookList() {
  return (
    <section className="booklist">
      {books.map((book) => {
        console.log(book);
        const { img, title, author } = book;
        return <Book img={img} title={title} author={author} />;
      })}
    </section>
  );
}
```

#### Key Prop

- typically it's going to be id
- always add key to component we are iterating and returning

```js
const books = [
  {
    author: "Jordan Moore",
    title: "Interesting Facts For Curious Minds",
    img: "./images/book-1.jpg",
    id: 1,
  },
  {
    author: "James Clear",
    title: "Atomic Habits",
    img: "https://images-na.ssl-images-amazon.com/images/I/81wgcld4wxL._AC_UL900_SR900,600_.jpg",
    id: 2,
  },
];

function BookList() {
  return (
    <section className="booklist">
      {books.map((book) => {
        console.log(book);
        const { img, title, author, id } = book;
        return <Book book={book} key={id} />;
      })}
    </section>
  );
}
```

- you will see index,but it's not advised if the list is changing

```js
function BookList() {
  return (
    <section className="booklist">
      {books.map((book, index) => {
        console.log(book);
        const { img, title, author, id } = book;
        return <Book book={book} key={index} />;
      })}
    </section>
  );
}
```

#### Pass The Entire Object

- render component
- pass entire object
- Destructuring (object)
  [JS Nuggets - Destructuring (object)](https://www.youtube.com/watch?v=i4vhNKihfto&list=PLnHJACx3NwAfRUcuKaYhZ6T5NRIpzgNGJ&index=8&t=1s)

```js
function BookList() {
  return (
    <section className="booklist">
      {books.map((book) => {
        console.log(book);
        const { img, title, author } = book;
        return <Book book={book} />;
      })}
    </section>
  );
}

const Book = (props) => {
  const { img, title, author } = props.book;

  return (
    <article className="book">
      <img src={img} alt={title} />
      <h2>{title}</h2>
      <h4>{author} </h4>
    </article>
  );
};
```

- alternative

```js
const Book = ({ book: { img, title, author } }) => {
  return (
    <article className="book">
      <img src={img} alt={title} />
      <h2>{title}</h2>
      <h4>{author} </h4>
    </article>
  );
};
```

#### My Personal Preference

- utilize spread operator (...) - copy values
- Spread Operator
- [JS Nuggets - Spread Operator](https://www.youtube.com/watch?v=4Zyr5a3m0Fc&list=PLnHJACx3NwAfRUcuKaYhZ6T5NRIpzgNGJ&index=10)

```js
const friends = ["john", "peter", "anna"];
const newFriends = [...friends, "susan"];
console.log(friends);
console.log(newFriends);
const someObject = {
  name: "john",
  job: "developer",
};
// COPY NOT A REFERENCE !!!!
const newObject = { ...someObject, location: "florida" };
console.log(someObject);
console.log(newObject);
```

```js
function BookList() {
  return (
    <section className="booklist">
      {books.map((book) => {
        return <Book {...book} key={book.id} />;
      })}
    </section>
  );
}

const Book = (props) => {
  const { img, title, author } = props;
  return (
    <article className="book">
      <img src={img} alt={title} />
      <h2>{title}</h2>
      <h4>{author} </h4>
    </article>
  );
};
const Book = ({ img, title, author }) => {
  // rest of the code
};
```

#### Events - Fundamentals

- Vanilla JS

```js
const btn = document.getElementById("btn");

btn.addEventListener("click", function (e) {
  // access event object
  // do something when event fires
});
```

- Similar approach
- Element, event, function
- Again camelCase

```js
const EventExamples = () => {
  const handleButtonClick = () => {
    alert("handle button click");
  };
  return (
    <section>
      <button onClick={handleButtonClick}>click me</button>
    </section>
  );
};
```

- [React Events](https://reactjs.org/docs/events.html)
- no need to memorize them(idea is the same)
- most common
  - onClick (click events)
  - onSubmit (submit form )
  - onChange (input change )

```js
function BookList() {
  return (
    <section className="booklist">
      <EventExamples />
      {books.map((book) => {
        return <Book {...book} key={book.id} />;
      })}
    </section>
  );
}

const EventExamples = () => {
  const handleFormInput = () => {
    console.log("handle form input");
  };
  const handleButtonClick = () => {
    alert("handle button click");
  };
  return (
    <section>
      <form>
        <h2>Typical Form</h2>
        <input
          type="text"
          name="example"
          onChange={handleFormInput}
          style={{ margin: "1rem 0" }}
        />
      </form>
      <button onClick={handleButtonClick}>click me</button>
    </section>
  );
};
```

#### Event Object and Form Submission

- in the case of form submit use button of type submit

```js
const EventExamples = () => {
  const handleFormInput = (e) => {
    console.log(e);
    // e.target - element
    console.log(`Input Name : ${e.target.name}`);
    console.log(`Input Value : ${e.target.value}`);
    // console.log('handle form input');
  };
  const handleButtonClick = () => {
    alert("handle button click");
  };
  const handleFormSubmission = (e) => {
    e.preventDefault();
    console.log("form submitted");
  };
  return (
    <section>
      {/* add onSubmit Event Handler */}
      <form onSubmit={handleFormSubmission}>
        <h2>Typical Form</h2>
        <input
          type="text"
          name="example"
          onChange={handleFormInput}
          style={{ margin: "1rem 0" }}
        />
        {/* add button with type='submit' */}
        <button type="submit">submit form</button>
      </form>
      <button onClick={handleButtonClick}>click me</button>
    </section>
  );
};
```

- alternative approach

```js
<button type="submit" onClick={handleFormSubmission}>
  submit form
</button>
```

#### Mind Grenade

- alternative approach
- pass anonymous function (in this case arrow function)
- one liner - less code

```js
const EventExamples = () => {
  return (
    <section>
      <button onClick={() => console.log("hello there")}>click me</button>
    </section>
  );
};
```

- also can access event object

```js
const EventExamples = () => {
  return (
    <section>
      <form>
        <h2>Typical Form</h2>
        <input
          type="text"
          name="example"
          onChange={(e) => console.log(e.target.value)}
          style={{ margin: "1rem 0" }}
        />
      </form>
      <button onClick={() => console.log("you clicked me")}>click me</button>
    </section>
  );
};
```

#### Mind Grenade #2

- remove EventsExamples
- components are independent by default
- what ever functionality component have it narrow down to same components

```js
function BookList() {
  return (
    <section className="booklist">
      {books.map((book) => {
        return <Book {...book} key={book.id} />;
      })}
    </section>
  );
}

const Book = (props) => {
  const { img, title, author } = props;
  const displayTitle = () => {
    console.log(title);
  };

  return (
    <article className="book">
      <img src={img} alt={title} />
      <h2>{title}</h2>
      <button onClick={displayTitle}>display title</button>
      <h4>{author} </h4>
    </article>
  );
};
```

- remove button

#### Prop Drilling

- react data flow - can only pass props down
- alternatives Context API, redux, other state libraries

```js
function BookList() {
  const someValue = "shakeAndBake";
  const displayValue = () => {
    console.log(someValue);
  };
  return (
    <section className="booklist">
      {books.map((book) => {
        return <Book {...book} key={book.id} displayValue={displayValue} />;
      })}
    </section>
  );
}

const Book = (props) => {
  const { img, title, author, displayValue } = props;

  return (
    <article className="book">
      <img src={img} alt={title} />
      <h2>{title}</h2>
      <button onClick={displayValue}>click me</button>
      <h4>{author} </h4>
    </article>
  );
};
```

#### More Complex Example

- initial setup
- create getBook function in booklist
- accepts id as an argument and finds the book
- [Javascript Nuggets - Filter and Find](https://www.youtube.com/watch?v=KeYxsev737s&list=PLnHJACx3NwAfRUcuKaYhZ6T5NRIpzgNGJ&index=4)
- pass the function down to Book Component and invoke on the button click
- in the Book Component destructure id and function
- invoke the function when user clicks the button, pass the id
- the goal : you should see the same book in the console

```js
const BookList = () => {
  const getBook = (id) => {
    const book = books.find((book) => book.id === id);
    console.log(book);
  };

  return (
    <section className="booklist">
      {books.map((book) => {
        return <Book {...book} key={book.id} getBook={getBook} />;
      })}
    </section>
  );
};

const Book = (props) => {
  const { img, title, author, getBook, id } = props;
  // console.log(props);

  return (
    <article className="book">
      <img src={img} alt={title} />
      <h2>{title}</h2>
      {/* this is not going to work */}
      <button onClick={getBook(id)}>display title</button>
      <h4>{author}</h4>
    </article>
  );
};
```

- two fixes
- first option - setup wrapper

```js
const Book = (props) => {
  const { img, title, author, getBook, id } = props;
  // console.log(props);
  const getSingleBook = () => {
    getBook(id);
  };
  return (
    <article className="book">
      <img src={img} alt={title} />
      <h2>{title}</h2>
      <button onClick={getSingleBook}>display title</button>
      <h4>{author}</h4>
    </article>
  );
};
```

- two fixes
- second option - wrap in the anonymous arrow function

```js
const Book = (props) => {
  const { img, title, author, getBook, id } = props;
  // console.log(props);
  const getSingleBook = () => {
    getBook(id);
  };
  return (
    <article className="book">
      <img src={img} alt={title} />
      <h2>{title}</h2>

      <button onClick={() => getBook(id)}>display title</button>
      <h4>{author}</h4>
    </article>
  );
};
```

#### Import and Export Statements

- remove all getBook code

```js
function BookList() {
  return (
    <section className="booklist">
      {books.map((book) => {
        return <Book {...book} key={book.id} />;
      })}
    </section>
  );
}

const Book = (props) => {
  const { img, title, author } = props;

  return (
    <article className="book">
      <img src={img} alt={title} />
      <h2>{title}</h2>

      <h4>{author} </h4>
    </article>
  );
};
```

- setup two files in src books.js and Book.js
- cut books array from index.js
- add to books.js

books.js

```js
const books = [
  {
    author: "Jordan Moore",
    title: "Interesting Facts For Curious Minds",
    img: "./images/book-1.jpg",
    id: 1,
  },
  {
    author: "James Clear",
    title: "Atomic Habits",
    img: "https://images-na.ssl-images-amazon.com/images/I/81wgcld4wxL._AC_UL900_SR900,600_.jpg",
    id: 2,
  },
];
```

- two flavors named and default exports

  - with named exports names MUST match
  - with default exports,can rename but only one per file

- named export

```js
export const books = [
  {
    author: "Jordan Moore",
    title: "Interesting Facts For Curious Minds",
    img: "./images/book-1.jpg",
    id: 1,
  },
  {
    author: "James Clear",
    title: "Atomic Habits",
    img: "https://images-na.ssl-images-amazon.com/images/I/81wgcld4wxL._AC_UL900_SR900,600_.jpg",
    id: 2,
  },
];
```

index.js

```js
import { books } from "./books";
```

- default export

```js
const Book = (props) => {
  const { img, title, author } = props;

  return (
    <article className="book">
      <img src={img} alt={title} />
      <h2>{title}</h2>

      <h4>{author} </h4>
    </article>
  );
};

export default Book;
```

index.js

```js
import Book from "./Book";
```

#### Local Images (src folder)

- better performance because optimized
- add one more book to array
- download all three images (rename)
- setup images folder in the src
- import all three images in the books.js
- set image property equal to import
- and yes each image requires new import

```js
import img1 from "./images/book-1.jpg";
import img2 from "./images/book-2.jpg";
import img3 from "./images/book-3.jpg";

export const books = [
  {
    author: "Jordan Moore",
    title: "Interesting Facts For Curious Minds",
    img: img1,
    id: 1,
  },
  {
    author: "James Clear",
    title: "Atomic Habits",
    img: img2,
    id: 2,
  },
  {
    author: "Stephen King",
    title: "Fairy Tale",
    img: img3,
    id: 3,
  },
];
```

#### Challenges

- setup numbers
- don't worry about css
- hint - index (second parameter in map)

index.js

```js
const BookList = () => {
  return (
    <section className="booklist">
      {books.map((book, index) => {
        return <Book {...book} key={book.id} number={index} />;
      })}
    </section>
  );
};

const Book = (props) => {
  const { img, title, author, number } = props;

  return (
    <article className="book">
      <img src={img} alt={title} />
      <h2>{title}</h2>

      <h4>{author}</h4>
      <span className="number">{`# ${number + 1}`}</span>
    </article>
  );
};
```

index.css

```css
.book {
  background: #fff;
  border-radius: 1rem;
  padding: 2rem;
  text-align: center;
  /* set relative */
  position: relative;
}

.number {
  position: absolute;
  top: 0;
  left: 0;
  font-size: 1rem;
  padding: 0.75rem;
  border-top-left-radius: 1rem;
  border-bottom-right-radius: 1rem;
  background: #c35600;
  color: #fff;
}
```

#### Add Title

- add a title to our app (css optional)
- change page title

index.js

```js
function BookList() {
  return (
    <>
      <h1>amazon best sellers</h1>
      <section className="booklist">
        {books.map((book) => {
          return <Book {...book} key={book.id} />;
        })}
      </section>
    </>
  );
}
```

index.css

```css
h1 {
  text-align: center;
  margin-top: 4rem;
  text-transform: capitalize;
}
```

public/index.html

```html
<title>Best Sellers</title>
```

#### Build Production Application

- stop the dev server "ctrl + c"
- run "npm run build"
- build folder gets created

#### Netlify

- sign up
- add new site/deploy manually
- choose build folder
- rename site - site settings/change site name

#### Create-React-App Boilerplate (src)

- index.js

```js
import React from "react";
import ReactDOM from "react-dom/client";

// styles (typically global)
import "./index.css";

// convention to name it App and setup in a separate file
import App from "./App";
// import report web vitals
import reportWebVitals from "./reportWebVitals";

// StrictMode

// StrictMode is a tool for highlighting potential problems in an application.Activates additional checks and warnings for its descendants.Runs only in Development, does not impact the production build. RENDERS TWICE !!! Possible to remove.

const root = ReactDOM.createRoot(document.getElementById("root"));
root.render(
  <React.StrictMode>
    <App />
  </React.StrictMode>
);

// If you want to start measuring performance in your app, pass a function
// to log results (for example: reportWebVitals(console.log))
// or send to an analytics endpoint. Learn more: https://bit.ly/CRA-vitals
reportWebVitals();
```

- remove in src

  - setupTests.js
  - reportWebVitals.js
  - App.test.js

- be careful with multiple css files

App.js

```js
function App() {
  return <h1>backroads app</h1>;
}

export default App;
```

- remove
  - remove logo.svg
  - App.css

#### Vite Docs

(Vite)[https://vitejs.dev/]

#### Vite Install

```sh
npm create vite@latest app-name -- --template react
npm install
npm run dev
```

- http://localhost:5173/

#### Vite Setup

- need to use .jsx extension
- index.html in the source instead of public
- assets still in public
- instead of index.js, need to use main.jsx
- to spin up dev server - "npm run dev"

- rest the same - imports/exports, deployment, assets, etc...

#### Event propagation

Event handlers will also catch events from any children your component might have. We say that an event “bubbles” or “propagates” up the tree: it starts with where the event happened, and then goes up the tree.

This <div> contains two buttons. Both the <div> and each button have their own onClick handlers. Which handlers do you think will fire when you click a button?

```jsx
export default function Toolbar() {
  return (
    <div
      className="Toolbar"
      onClick={() => {
        alert("You clicked on the toolbar!");
      }}
    >
      <button onClick={() => alert("Playing!")}>Play Movie</button>
      <button onClick={() => alert("Uploading!")}>Upload Image</button>
    </div>
  );
}
```

Event handlers receive an event object as their only argument. By convention, it’s usually called e, which stands for “event”. You can use this object to read information about the event.

That event object also lets you stop the propagation. If you want to prevent an event from reaching parent components, you need to call e.stopPropagation()

```jsx
function Button({ onClick, children }) {
  return (
    <button
      onClick={(e) => {
        e.stopPropagation();
        onClick();
      }}
    >
      {children}
    </button>
  );
}

export default function Toolbar() {
  return (
    <div
      className="Toolbar"
      onClick={() => {
        alert("You clicked on the toolbar!");
      }}
    >
      <Button onClick={() => alert("Playing!")}>Play Movie</Button>
      <Button onClick={() => alert("Uploading!")}>Upload Image</Button>
    </div>
  );
}
```

e.preventDefault() to remove default behavior

# Advance React

- Hooks: useState, useEffects, useRef, useContext, useReducer, etc
- Forms: controlled/uncontrolled inputs values, onChange, FormDate API
- Context API, Prop Drilling, custom Hooks, Performance
- The [ and ] syntax here is called array destructuring and it lets you read values from an array. The array returned by useState always has exactly two items.
- Internally, React holds an array of state pairs for every component. It also maintains the current pair index, which is set to 0 before rendering. Each time you call useState, React gives you the next state pair and increments the index.
- below is how useState work

```jsx

let state = [];
let setters = [];
let firstRun = true;
let cursor = 0;

function createSetter(cursor) {
  return function setterWithCursor(newVal) {
    state[cursor] = newVal;
  };
}

// This is the pseudocode for the useState helper
export function useState(initVal) {
  if (firstRun) {
    state.push(initVal);
    setters.push(createSetter(cursor));
    firstRun = false;
  }

  const setter = setters[cursor];
  const value = state[cursor];

  cursor++;
  return [value, setter];
}

// Our component code that uses hooks
function RenderFunctionComponent() {
  const [firstName, setFirstName] = useState("Rudi"); // cursor: 0
  const [lastName, setLastName] = useState("Yardley"); // cursor: 1

  return (
    <div>
      <Button onClick={() => setFirstName("Richard")}>Richard</Button>
      <Button onClick={() => setFirstName("Fred")}>Fred</Button>
    </div>
  );
}

// This is sort of simulating Reacts rendering cycle
function MyComponent() {
  cursor = 0; // resetting the cursor
  return <RenderFunctionComponent />; // render
}

console.log(state); // Pre-render: []
MyComponent();
console.log(state); // First-render: ['Rudi', 'Yardley']
MyComponent();
console.log(state); // Subsequent-render: ['Rudi', 'Yardley']

// click the 'Fred' button

console.log(state); // After-click: ['Fred', 'Yardley']
view rawhooks-state-pseudocode.js hosted with ❤ by GitHub

```

- State is local to a component instance on the screen

- Imagine that your components are cooks in the kitchen, assembling tasty dishes from ingredients. In this scenario, React is the waiter who puts in requests from customers and brings them their orders. This process of requesting and serving UI has three steps:

1. Triggering a render (delivering the guest’s order to the kitchen)
2. Rendering the component (preparing the order in the kitchen)
3. Committing to the DOM (placing the order on the table)

## Rendering

After you trigger a render, React calls your components to figure out what to display on screen. “Rendering” is React calling your components.

- On initial render, React will call the root component.
- For subsequent renders, React will call the function component whose state update triggered the render.
- During the initial render, React will create the DOM nodes for <section>, <h1>, and three <img> tags.
- During a re-render, React will calculate which of their properties, if any, have changed since the previous render. It won’t do anything with that information until the next step, the commit phase.
- For the initial render, React will use the appendChild() DOM API to put all the DOM nodes it has created on screen.
- For re-renders, React will apply the minimal necessary operations (calculated while rendering!) to make the DOM match the latest rendering output.

React only changes the DOM nodes if there’s a difference between renders. For example, here is a component that re-renders with different props passed from its parent every second. Notice how you can add some text into the <input>, updating its value, but the text doesn’t disappear when the component re-renders:

- https://react.dev/learn/state-as-a-snapshot

This lets you update multiple state variables—even from multiple components—without triggering too many re-renders. But this also means that the UI won’t be updated until after your event handler, and any code in it, completes. This behavior, also known as batching, makes your React app run much faster. It also avoids dealing with confusing “half-finished” renders where only some of the variables have been updated.

State can hold any kind of JavaScript value, including objects. But you shouldn’t change objects that you hold in the React state directly. Instead, when you want to update an object, you need to create a new one (or make a copy of an existing one), and then set the state to use that copy.

force a component to reset its state by passing it a different key, like <Chat key={email} />. This tells React that if the recipient is different, it should be considered a different Chat component that needs to be re-created from scratch with the new data (and UI like inputs). Now switching between the recipients resets the input field—even though you render the same component.

- Same component at the same position preserves state

```jsx
import { useState } from "react";

export default function App() {
  const [isFancy, setIsFancy] = useState(false);
  return (
    <div>
      {isFancy ? <Counter isFancy={true} /> : <Counter isFancy={false} />}
      <label>
        <input
          type="checkbox"
          checked={isFancy}
          onChange={(e) => {
            setIsFancy(e.target.checked);
          }}
        />
        Use fancy styling
      </label>
    </div>
  );
}

function Counter({ isFancy }) {
  const [score, setScore] = useState(0);
  const [hover, setHover] = useState(false);

  let className = "counter";
  if (hover) {
    className += " hover";
  }
  if (isFancy) {
    className += " fancy";
  }

  return (
    <div
      className={className}
      onPointerEnter={() => setHover(true)}
      onPointerLeave={() => setHover(false)}
    >
      <h1>{score}</h1>
      <button onClick={() => setScore(score + 1)}>Add one</button>
    </div>
  );
}
```

- State is tied to a position in the render tree

```jsx
import { useState } from "react";

export default function App() {
  const counter = <Counter />;
  return (
    <div>
      {counter}
      {counter}
    </div>
  );
}

function Counter() {
  const [score, setScore] = useState(0);
  const [hover, setHover] = useState(false);

  let className = "counter";
  if (hover) {
    className += " hover";
  }

  return (
    <div
      className={className}
      onPointerEnter={() => setHover(true)}
      onPointerLeave={() => setHover(false)}
    >
      <h1>{score}</h1>
      <button onClick={() => setScore(score + 1)}>Add one</button>
    </div>
  );
}
```

- Different components at the same position reset state
- You might have seen keys when rendering lists. Keys aren’t just for lists! You can use keys to make React distinguish between any components

## Setup

- traditional Vite app
  - removed boilerplate
  - provided some assets (css, data)
    - just so we can focus on important stuff
  - removed <StrictMode>, so it's less logs

## Advanced Topics

- /tutorial directory
- work in the starter folder
- complete code in the final folder
- in order to work on topic import component from 'starter'
- in order to test final import component from 'final'
- setup challenges
- in the beginning examples with numbers and buttons :):):)

```js
import Starter from "./tutorial/1-useState/starter/1-error-example";
import Final from "./tutorial/1-useState/final/1-error-example";
function App() {
  return (
    <div className="container">
      <Starter />
      <Final />
    </div>
  );
}

export default App;
```

#### The Need For State

```js
import Starter from "./tutorial/01-useState/starter/01-error-example.jsx";
```

- in App.jsx setup import and container div

  Setup Challenge :

- create count variable
- display value in the JSX
- add button and increase the value
- the reason for bug - we don't trigger re-render (reference next lecture)

```js
const ErrorExample = () => {
  let count = 0;

  const handleClick = () => {
    count = count + 1;
    console.log(count);
    // preserve value between renders
    // trigger re-render
  };
  return (
    <div>
      <h2>{count}</h2>
      <button type="button" className="btn" onClick={handleClick}>
        increment
      </button>
    </div>
  );
};

export default ErrorExample;
```

#### useState Basics

```js
import Starter from "./tutorial/01-useState/starter/02-useState-basics.jsx";
```

[Javascript Nuggets - Destructuring (Array)](https://www.youtube.com/watch?v=qhECs40xMec&list=PLnHJACx3NwAfRUcuKaYhZ6T5NRIpzgNGJ&index=7&t=9s)

- useState hook
- returns an array with two elements: the current state value, and a function that we can use to update the state
- accepts default value as an argument
- state update triggers re-render

```js
import { useState } from "react";

const UseStateBasics = () => {
  // console.log(useState());
  // console.log(useState('jo koy'));
  // const value = useState()[0];
  // const handler = useState()[1];
  // console.log(value, handler);

  const [count, setCount] = useState(0);
  const handleClick = () => {
    // console.log(count)
    setCount(count + 1);
    // be careful, we can set any value
    // setCount('pants');
  };
  return (
    <div>
      <h4>You clicked {count} times</h4>
      <button className="btn" onClick={handleClick}>
        Click me
      </button>
    </div>
  );
};

export default UseStateBasics;
```

#### Initial Render and Re-Renders

In a React application, the initial render is the first time that the component tree is rendered to the DOM. It happens when the application first loads, or when the root component is first rendered. This is also known as "mounting" the components.

Re-renders, on the other hand, happen when the component's state or props change, and the component needs to be updated in the DOM to reflect these changes. React uses a virtual DOM to optimize the process of updating the actual DOM, so that only the necessary changes are made.

There are a few ways that you can trigger a re-render in a React component:

- By changing the component's state or props. When the component's state or props change, React will re-render the component to reflect these changes.

- When the parent element re-renders, even if the component's state or props have not changed.

#### General Rules of Hooks

- starts with "use" (both -react and custom hooks)
- component must be uppercase
- invoke inside function/component body
- don't call hooks conditionally (cover later)
- set functions don't update state immediately (cover later)

#### useState with Array

```js
import Starter from "./tutorial/01-useState/starter/03-useState-array.jsx";
```

Setup Challenge :

- import data
- setup a state value
  - people - default value equal to data
- display list(people) in the browser

- create two functions

  - one that removes single item from the list
  - one that clears entire list

1. render the list

```js
import React from "react";
import { data } from "../../../data";
const UseStateArray = () => {
  const [people, setPeople] = React.useState(data);

  return (
    <div>
      {people.map((person) => {
        const { id, name } = person;
        return (
          <div key={id} className="item">
            <h4>{name}</h4>
          </div>
        );
      })}
    </div>
  );
};

export default UseStateArray;
```

2. remove items

[Javascript Nuggets - Filter and Find](https://www.youtube.com/watch?v=KeYxsev737s&list=PLnHJACx3NwAfRUcuKaYhZ6T5NRIpzgNGJ&index=4)

```js
import React from "react";
import { data } from "../../../data";
const UseStateArray = () => {
  const [people, setPeople] = React.useState(data);

  const removeItem = (id) => {
    let newPeople = people.filter((person) => person.id !== id);
    setPeople(newPeople);
  };
  return (
    <div>
      {people.map((person) => {
        const { id, name } = person;
        return (
          <div key={id} className="item">
            <h4>{name}</h4>
            <button onClick={() => removeItem(id)}>remove</button>
          </div>
        );
      })}
      <button
        className="btn"
        style={{ marginTop: "2rem" }}
        onClick={() => setPeople([])}
      >
        clear items
      </button>
    </div>
  );
};

export default UseStateArray;
```

- should we update backroads app project?

#### useState with Object

```js
import Starter from "./tutorial/01-useState/starter/04-useState-object.jsx";
```

Setup Challenge :

- setup three state values
  - name(string)
  - age(number)
  - hobby(string)
- render in the browser
- create a button
  - setup a function
    - update all three state values
- as a result once the user clicks the button,
  new person is displayed in the browser

```js
import { useState } from "react";

const UseStateObject = () => {
  const [name, setName] = useState("peter");
  const [age, setAge] = useState(24);
  const [hobby, setHobby] = useState("read books");

  const displayPerson = () => {
    setName("john");
    setAge(28);
    setHobby("scream at the computer");
  };
  return (
    <>
      <h3>{name}</h3>
      <h3>{age}</h3>
      <h4>Enjoys To: {hobby}</h4>
      <button className="btn" onClick={displayPerson}>
        show john
      </button>
    </>
  );
};

export default UseStateObject;
```

#### Automatic Batching

In React, "batching" refers to the process of grouping multiple state updates into a single update. This can be useful in certain cases because it allows React to optimize the rendering of your components by minimizing the number of DOM updates that it has to perform.

By default, React uses a technique called "auto-batching" to group state updates that occur within the same event loop into a single update. This means that if you call the state update function multiple times in a short period of time, React will only perform a single re-render for all of the updates.

React 18 ensures that state updates invoked from any location will be batched by default. This will batch state updates, including native event handlers, asynchronous operations, timeouts, and intervals.

#### Switch to Object

```js
import { useState } from "react";

const UseStateObject = () => {
  const [person, setPerson] = useState({
    name: "peter",
    age: 24,
    hobby: "read books",
  });

  const displayPerson = () => {
    setPerson({ name: "john", age: 28, hobby: "scream at the computer" });
    // be careful, don't overwrite
    // setPerson('shakeAndBake');
    // setPerson({ name: 'susan' });
    // setPerson({ ...person, name: 'susan' });
  };
  return (
    <>
      <h3>{person.name}</h3>
      <h3>{person.age}</h3>
      <h4>Enjoys To: {person.hobby}</h4>
      <button className="btn" onClick={displayPerson}>
        show john
      </button>
    </>
  );
};

export default UseStateObject;
```

#### Set Function "Gotcha"

```js
import Starter from "./tutorial/01-useState/starter/05-useState-gotcha.jsx";
```

Setup Challenge :

- setup a state value and the button
- add functionality to increase value by 1
- log a state value, right after setFunction

Keep in mind that the state update function setState does not immediately mutate the state. Instead, it schedules an update to the state and tells React that it needs to re-render the component. The actual state update will be performed as part of the next rendering cycle. Be mindful when you need to set state value based on a different state value.

trivial example

```js
import { useState } from "react";

const UseStateGotcha = () => {
  const [value, setValue] = useState(0);

  const handleClick = () => {
    setValue(value + 1);
    //  be careful it's the old value
    console.log(value);
    //  so if you have any functionality
    // that relies on the latest value
    // it will be wrong !!!
  };
  return (
    <div>
      <h1>{value}</h1>
      <button className="btn" onClick={handleClick}>
        increase
      </button>
    </div>
  );
};

export default UseStateGotcha;
```

If you want to update the state immediately and synchronously, you can pass a function to setState that receives the previous state as an argument and returns the new state. For example:

```js
setState((prevState) => {
  return { ...prevState, value: newValue };
});
```

This can be useful if you need to update the state based on the previous state, or if you need to update the state synchronously.

```js
const handleClick = () => {
  setValue((currentState) => {
    // must return otherwise undefined
    // below is the latest/current state value
    const newState = currentState + 1;
    return newState;
  });
};
```

- setTimeout Example

```js
const handleClick = () => {
  // setTimeout(() => {
  // console.log('clicked the button');
  //   setValue(value + 1);
  // }, 3000);
  setTimeout(() => {
    console.log("clicked the button");
    setValue((currentState) => {
      return currentState + 1;
    });
  }, 3000);
};
```

- as an example refactor code in
  /tutorial/01-useState/03-useState-array
- should we use functional update approach for everything?

#### Code Example

```js
import Starter from "./tutorial/02-useEffect/starter/01-code-example.jsx";
```

```js
import { useState } from "react";

const ComponentExample = () => {
  const [value, setValue] = useState(0);
  const sayHello = () => {
    console.log("hello there");
    // be careful
    // setValue(value + 1);
  };
  sayHello();
  return (
    <div>
      <h1>value : {value}</h1>
      <button className="btn" onClick={() => setValue(value + 1)}>
        click me
      </button>
    </div>
  );
};
export default ComponentExample;
```

- the problem starts when we update the state

```js
const [value, setValue] = useState(0);

const sayHello = () => {
  console.log("hello there");
  // be careful, you will have infinite loop
  setValue(value + 1);
};
sayHello();
```

- initial render - setup state value and invoke sayHello
- in the sayHello update state, trigger re-render

- re-render - setup state value and invoke sayHello
- in the sayHello update state, trigger re-render

- repeat
- repeat
- repeat
  ..................................................

- but what about fetching data?

#### useEffect Basics

```js
import Starter from "./tutorial/02-useEffect/starter/02-useEffect-basics.jsx";
```

useEffect is a hook in React that allows you to perform side effects in function components.There is no need for urban dictionary - basically any work outside of the component. Some examples of side effects are: subscriptions, fetching data, directly updating the DOM, event listeners, timers, etc.

- useEffect hook
- accepts two arguments (second optional)
- first argument - cb function
- second argument - dependency array
- by default runs on each render (initial and re-render)
- cb can't return promise (so can't make it async)
- if dependency array empty [] runs only on initial render

```js
import { useState, useEffect } from "react";

const UseEffectBasics = () => {
  const [value, setValue] = useState(0);
  const sayHello = () => {
    console.log("hello there");
  };

  sayHello();

  // useEffect(() => {
  //   console.log('hello from useEffect');
  // });

  useEffect(() => {
    console.log("hello from useEffect");
  }, []);
  return (
    <div>
      <h1>value : {value}</h1>
      <button className="btn" onClick={() => setValue(value + 1)}>
        click me
      </button>
    </div>
  );
};
export default UseEffectBasics;
```

#### Multiple Effects

```js
import Starter from "./tutorial/02-useEffect/starter/03-multiple-effects.jsx";
```

```js
import { useState, useEffect } from "react";

const MultipleEffects = () => {
  const [value, setValue] = useState(0);
  const [secondValue, setSecondValue] = useState(0);

  useEffect(() => {
    console.log("hello from first useEffect");
  }, [value]);

  useEffect(() => {
    console.log("hello from second useEffect");
  }, [secondValue]);
  return (
    <div>
      <h1>value : {value}</h1>
      <button className="btn" onClick={() => setValue(value + 1)}>
        value
      </button>
      <h1>second value : {secondValue}</h1>
      <button className="btn" onClick={() => setSecondValue(secondValue + 1)}>
        second value
      </button>
    </div>
  );
};
export default MultipleEffects;
```

#### Fetch Data

```js
import Starter from "./tutorial/02-useEffect/starter/04-fetch-data.jsx";
```

[Javascript Nuggets - Fetch API](https://www.youtube.com/watch?v=C_VIKzfpRrg&list=PLnHJACx3NwAfRUcuKaYhZ6T5NRIpzgNGJ&index=18&t=343s)

- later in the course we will use axios

Setup Challenge :

- import useState and useEffect
- setup state value
  - users - default value []
- setup useEffect
- MAKE SURE IT RUNS ONLY ON INITIAL RENDER
- in the cb, create a function which performs fetch functionality
  - use url I provided in the starter file
  - you can use .then or async
  - set users equal to result
  - iterate over the list and display image, user name and link
- DON'T WORRY ABOUT CSS, MOST IMPORTANT LOGIC !!!

```js
import { useState, useEffect } from "react";

const url = "https://api.github.com/users";

const FetchData = () => {
  const [users, setUsers] = useState([]);

  useEffect(() => {
    // you can also setup function outside
    const fetchData = async () => {
      try {
        const response = await fetch(url);
        const users = await response.json();
        setUsers(users);
      } catch (error) {
        console.log(error);
      }
    };
    fetchData();
  }, []);
  return (
    <section>
      <h3>github users</h3>
      <ul className="users">
        {users.map((user) => {
          const { id, login, avatar_url, html_url } = user;
          return (
            <li key={id}>
              <img src={avatar_url} alt={login} />
              <div>
                <h5>{login}</h5>
                <a href={html_url}>profile</a>
              </div>
            </li>
          );
        })}
      </ul>
    </section>
  );
};
export default FetchData;
```

#### Cleanup Function

```js
import Starter from "./tutorial/02-useEffect/starter/05-cleanup-function.jsx";
```

Will Cover After 03-conditional-rendering

- Setup Challenge :

- create state value
- in jsx return button which toggles state value
- based on condition return second component (simple return)
- inside second component create useEffect and run it only on initial render

```js
import { useEffect, useState } from "react";

const CleanupFunction = () => {
  const [toggle, setToggle] = useState(false);
  return (
    <div>
      <button className="btn" onClick={() => setToggle(!toggle)}>
        toggle component
      </button>
      {toggle && <RandomComponent />}
    </div>
  );
};
const RandomComponent = () => {
  useEffect(() => {
    console.log("hmm, this is interesting");
  }, []);
  return <h1>hello there</h1>;
};
export default CleanupFunction;
```

Vanilla JS

```js
const intID = setInterval(() => {
  console.log("hello from interval");
}, 1000);
clearInterval(intID);
```

```js
const someFunc = () => {
  // some logic here
};
window.addEventListener("scroll", someFunc);
window.removeEventListener("scroll", someFunc);
```

```js
import { useEffect, useState } from "react";

const CleanupFunction = () => {
  const [toggle, setToggle] = useState(false);
  return (
    <div>
      <button className="btn" onClick={() => setToggle(!toggle)}>
        toggle component
      </button>
      {toggle && <RandomComponent />}
    </div>
  );
};
const RandomComponent = () => {
  useEffect(() => {
    // console.log('hmm, this is interesting');
    const intID = setInterval(() => {
      console.log("hello from interval");
    }, 1000);
    // does not stop, keeps going
    // every time we render component new interval gets created
    return () => clearInterval(intID);
  }, []);
  return <h1>hello there</h1>;
};
export default CleanupFunction;
```

```js
useEffect(() => {
  // console.log('hmm, this is interesting');
  const someFunc = () => {
    // some logic here
  };
  window.addEventListener("scroll", someFunc);
  return () => window.removeEventListener("scroll", someFunc);
}, []);
```

#### You Might Not Need an Effect

[You Might Not Need an Effect](https://beta.reactjs.org/learn/you-might-not-need-an-effect)

- will still utilize useEffect
- there is still plenty of code using useEffect

- fetching data
  replaced by libraries - react query, rtk query, swr or next.js

```js
import { useHook } from "library";

function Example() {
  const { data, error, isLoading } = useHook("url", fetcher);

  if (error) return <div>failed to load</div>;
  if (isLoading) return <div>loading...</div>;
  return <div>hello {data.name}!</div>;
}
```

- rest of them by refactoring code

#### Multiple Returns - Basics

```js
import Starter from "./tutorial/03-conditional-rendering/starter/01-multiple-returns-basics.jsx";
```

Vanilla JS

```js
const sayHello = (name) => {
  if (name) {
    return `Hello, ${name}`;
    // exit the function, skip rest of the code
  }
  // so if name provided, won't get to this line
  return "Hello, there";
};

const firstResp = sayHello("john");
console.log(firstResp); // Hello, john
const secondResp = sayHello();
console.log(secondResp); // Hello, there
```

- if no explicit return by default function returns 'undefined'

```js
import { useEffect, useState } from "react";

const MultipleReturnsBasics = () => {
  // while fetching data
  // convention with boolean values "isSomething"
  const [isLoading, setIsLoading] = useState(true);

  useEffect(() => {
    setTimeout(() => {
      // done fetching data
      setIsLoading(false);
    }, 3000);
  }, []);

  // can return entire app
  if (isLoading) {
    return <h2>Loading...</h2>;
  }

  return <h2>My App</h2>;
};
export default MultipleReturnsBasics;
```

#### Multiple Returns - Fetch Data

```js
import Starter from "./tutorial/03-conditional-rendering/starter/02-multiple-returns-fetch-data.jsx";
```

Setup Challenge :

- practice on setting up state values and data fetching
- create state variable
  - user - default value null
- fetch data from the url (for now just log result)
- if you see user object in the console, continue with the videos

```js
import { useEffect, useState } from "react";
const url = "https://api.github.com/users/QuincyLarson";

const MultipleReturnsFetchData = () => {
  const [user, setUser] = useState(null);

  useEffect(() => {
    const fetchUser = async () => {
      try {
        const resp = await fetch(url);
        const user = await resp.json();
        console.log(user);
      } catch (error) {
        // fetch only cares about network errors
        // will work with axios
        console.log(error);
      }
    };
    fetchUser();
  }, []);

  return <h2>Fetch Example</h2>;
};
export default MultipleReturnsFetchData;
```

Data Fetching :

- usually three options

  - loading - waiting for data to arrive (display loading state)
  - error - there was an error (display error message)
  - success - received data (display data)

```js
import { useEffect, useState } from "react";
const url = "https://api.github.com/users/QuincyLarson";

const MultipleReturnsFetchData = () => {
  // convention to setup booleans with isSomething
  const [isLoading, setIsLoading] = useState(true);
  const [isError, setIsError] = useState(false);
  const [user, setUser] = useState(null);

  useEffect(() => {
    const fetchUser = async () => {
      try {
        const resp = await fetch(url);
        const user = await resp.json();
        // console.log(user);
        setUser(user);
      } catch (error) {
        setIsError(true);
        console.log(error);
      }
      // hide loading
      setIsLoading(false);
    };
    fetchUser();
  }, []);
  // order matters
  // don't place user JSX before loading or error
  if (isLoading) {
    return <h2>Loading...</h2>;
  }
  if (isError) {
    return <h2>There was an error...</h2>;
  }
  return (
    <div>
      <img
        style={{ width: "150px", borderRadius: "25px" }}
        src={user.avatar_url}
        alt={user.name}
      />
      <h2>{user.name}</h2>
      <h4>works at {user.company}</h4>
      <p>{user.bio}</p>
    </div>
  );
};
export default MultipleReturnsFetchData;
```

#### Fetch Errors "Gotcha" (optional)

```js
import Starter from "./tutorial/03-conditional-rendering/starter/02-multiple-returns-fetch-data.jsx";
```

Unlike for example Axios, by default, the fetch() API does not consider HTTP status codes in the 4xx or 5xx range to be errors. Instead, it considers these status codes to be indicative of a successful request,

```js
try {
const resp = await fetch(url);
// console.log(resp);
if (!resp.ok) {
  setIsError(true);
  setIsLoading(false);
  return;
}

const user = await resp.json();
setUser(user);

}

```

#### Order Matters - Setup

```js
import Starter from "./tutorial/03-conditional-rendering/starter/02-multiple-returns-fetch-data.jsx";
```

Please don't dismiss this topic. A lot of questions in course Q&A.

Challenge :

- destructure properties and remove user from JSX
- you might or might not encounter the bug

```js
return (
  <div>
    <img
      style={{ width: "100px", borderRadius: "25px" }}
      src={avatar_url}
      alt={name}
    />
    <h2>{name}</h2>
    <h4>works at {company}</h4>
    <p>{bio}</p>
  </div>
);
```

#### Order Matters - Solution

- before returns

```js
const [user, setUser] = useState(null);
console.log(user); // still null
// we can't pull out properties from null
const { avatar_url, name, company, bio } = user;
```

- after returns

```js
console.log(user); // user object;
const { avatar_url, name, company, bio } = user;
```

```js
return (
  <div>
    <img
      style={{ width: "100px", borderRadius: "25px" }}
      src={avatar_url}
      alt={name}
    />
    <h2>{name}</h2>
    <h4>works at {company}</h4>
    <p>{bio}</p>
  </div>
);
```

Vanilla JS

```js
const someObject = {
  name: "jo koy",
};
// this is cool
someObject.name; // returns 'jo koy'
someObject.propertyThatDoesNotExist; // returns undefined

// not cool at all, javascript will scream, yell and complain
const randomValue = null;
randomValue.name;

// this is ok
const randomList = [];
console.log(randomList[0]); // returns undefined

// not cool at all, javascript will scream, yell and complain
console.log(randomList[0].name);
```

#### Fetch Function Location

```js
const fetchData = async () => {
  // fetch data
};

useEffect(() => {
  fetchData();
}, []);
```

- DON'T ADD fetchData to dependency array !!!
- IT WILL TRIGGER INFINITE LOOP !!!

#### DON'T CALL HOOKS CONDITIONALLY

```js
import Starter from "./tutorial/03-conditional-rendering/starter/03-hooks-rule.jsx";
```

```js
import { useState, useEffect } from "react";

const Example = () => {
  const [condition, setCondition] = useState(true);
  if (condition) {
    // won't work
    const [state, setState] = useState(false);
  }

  if (condition) {
    return <h2>Hello There</h2>;
  }
  // this will also fail
  useEffect(() => {
    console.log("hello there");
  }, []);
  return <h2>example</h2>;
};

export default Example;
```

#### Truthy and Falsy Values (optional)

Vanilla JS

In JavaScript, a value is considered "truthy" if it is evaluated to true when used in a boolean context. A value is considered "falsy" if it is evaluated to false when used in a boolean context.

Here is a list of values that are considered falsy in JavaScript:

false
0 (zero)
"" (empty string)
null
undefined
NaN (Not a Number)
All other values, including objects and arrays, are considered truthy.

For example:

```js
const x = "Hello";
const y = "";
const z = 0;

if (x) {
  console.log("x is truthy");
}

if (y) {
  console.log("y is truthy");
} else {
  console.log("y is falsy");
}

if (z) {
  console.log("z is truthy");
} else {
  console.log("z is falsy");
}

// Output:
// "x is truthy"
// "y is falsy"
// "z is falsy"
```

In this example, the variable x is a non-empty string, which is considered truthy, so the first if statement is executed. The variable y is an empty string, which is considered falsy, so the else block of the second if statement is executed. The variable z is the number 0, which is considered falsy, so the else block of the third if statement is executed.

#### Short Circuit Evaluation (optional)

Vanilla JS

In JavaScript, short-circuit evaluation is a technique that allows you to use logical operators (such as && and ||) to perform conditional evaluations in a concise way.

The && operator (logical AND) returns the first operand if it is "falsy", or the second operand if the first operand is "truthy".

For example:

```js
const x = 0;
const y = 1;

console.log(x && y); // Output: 0 (the first operand is falsy, so it is returned)
console.log(y && x); // Output: 0 (the second operand is falsy, so it is returned)
```

The || operator (logical OR) returns the first operand if it is "truthy", or the second operand if the first operand is "falsy".

For example:

```js
const x = 0;
const y = 1;

console.log(x || y); // Output: 1 (the first operand is falsy, so the second operand is returned)
console.log(y || x); // Output: 1 (the first operand is truthy, so it is returned)
```

Short-circuit evaluation can be useful in cases where you want to perform a certain action only if a certain condition is met, or you want to return a default value if a certain condition is not met.

For example:

```js
function displayName(name) {
  return name || "Anonymous";
}

console.log(displayName("Pizza")); // Output: "Pizza"
console.log(displayName()); // Output: "Anonymous"
```

In this example, the displayName() function returns the name property of the user object if it exists, or "Anonymous" if the name property is not present. This is done using the || operator and short-circuit evaluation.

#### Short Circuit Evaluation React - Basics

```js
import Starter from "./tutorial/03-conditional-rendering/starter/04-short-circuit-overview.jsx";
```

Setup Challenge :

- create two state values
- one "falsy" and second "truthy"
- setup both conditions for each operator in JSX - hint {}
  - || OR
  - && AND

```js
import { useState } from "react";

const ShortCircuitOverview = () => {
  // falsy
  const [text, setText] = useState("");
  // truthy
  const [name, setName] = useState("susan");

  const codeExample = text || "hello world";

  // can't use if statements
  return (
    <div>
      {/* {if(someCondition){"won't work"}} */}

      <h4>Falsy OR : {text || "hello world"}</h4>
      <h4>Falsy AND : {text && "hello world"}</h4>
      <h4>Truthy OR : {name || "hello world"}</h4>
      <h4>Truthy AND : {name && "hello world"}</h4>
      {codeExample}
    </div>
  );
};
export default ShortCircuitOverview;
```

#### Short Circuit Evaluation in React - Common Approaches

```js
import Starter from "./tutorial/03-conditional-rendering/starter/05-short-circuit-examples.jsx";
```

Vanilla JS (Optional)
The ! operator is a logical operator in JavaScript that negates a boolean value. It is equivalent to the not operator in other programming languages.

For example:

```js
let isTrue = true;
let isFalse = false;

console.log(!isTrue); // outputs: false
console.log(!isFalse); // outputs: true
```

You can use the ! operator to test if a value is not truthy or falsy:

```js
let val = 0;
if (!val) {
  console.log("val is falsy");
}
```

You can also use the ! operator to convert a value to a boolean and negate it:

```js
let val = "hello";
let bool = !val; // bool is now false

val = "";
bool = !val; // bool is now true
```

```js
import { useState } from "react";

const ShortCircuitOverview = () => {
  // falsy
  const [text, setText] = useState("");
  // truthy
  const [name, setName] = useState("susan");
  const [user, setUser] = useState({ name: "john" });
  const [isEditing, setIsEditing] = useState(false);

  // can't use if statements
  return (
    <div>
      <h2>{text || "default value"}</h2>
      {text && (
        <div>
          <h2> whatever return</h2>
          <h2>{name}</h2>
        </div>
      )}
      {/* more info below */}
      {!text && (
        <div>
          <h2> whatever return</h2>
          <h2>{name}</h2>
        </div>
      )}
      {user && <SomeComponent name={user.name} />}
      <h2 style={{ margin: "1rem 0" }}>Ternary Operator</h2>
      <button className="btn">{isEditing ? "edit" : "add"}</button>
      {user ? (
        <div>
          <h4>hello there user {user.name}</h4>
        </div>
      ) : (
        <div>
          <h2>please login</h2>
        </div>
      )}
    </div>
  );
};

const SomeComponent = ({ name }) => {
  return (
    <div>
      <h4>hello there, {name}</h4>
      <button className="btn">log out</button>
    </div>
  );
};
export default ShortCircuitEvaluation;
```

#### Ternary Operator

Vanilla JS

In JavaScript, the ternary operator is a way to concisely express a simple conditional statement. It is often called the "conditional operator" or the "ternary conditional operator".

Here is the basic syntax for using the ternary operator:

```js
condition ? expression1 : expression2;
```

If condition is truthy, the operator will return expression1. If condition is falsy, it will return expression2.

Jobster Example

[Jobster ](https://redux-toolkit-jobster.netlify.app/landing)

#### Toggle Challenge

```js
import Starter from "./tutorial/03-conditional-rendering/starter/06-toggle-challenge.jsx";
```

- create state value (boolean)
- return a button and a component/element
- when user clicks the button
  - toggle state value
  - conditionally render component/element

Initial Setup

```js
import { useState } from "react";

const ToggleChallenge = () => {
  const [showAlert, setShowAlert] = useState(false);

  const toggleAlert = () => {
    if (showAlert) {
      setShowAlert(false);
      return;
    }
    setShowAlert(true);
  };

  return (
    <div>
      <button className="btn" onClick={toggleAlert}>
        toggle alert
      </button>
      {showAlert && <Alert />}
    </div>
  );
};

const Alert = () => {
  return <div className="alert alert-danger">hello world</div>;
};
export default ToggleChallenge;
```

Improvements

```js
<button className='btn' onClick={() => setShowAlert(!showAlert)}>
```

#### User Challenge

```js
import Starter from "./tutorial/03-conditional-rendering/starter/07-user-challenge.jsx";
```

- create state value
  - user - default value null
- create two functions
  - login - set's user equal to object with name property
  - logout - set's user equal to null
- in jsx use ? to display two different setups

- h4 with "hello there, user name" and logout button
- h4 with "please login " and login button

```js
import { useState } from "react";

const UserChallenge = () => {
  const [user, setUser] = useState(null);

  const login = () => {
    // normally connect to db or api
    setUser({ name: "vegan food truck" });
  };
  const logout = () => {
    setUser(null);
  };

  return (
    <div>
      {user ? (
        <div>
          <h4>hello there, {user.name}</h4>
          <button className="btn" onClick={logout}>
            logout
          </button>
        </div>
      ) : (
        <div>
          <h4>Please Login</h4>
          <button className="btn" onClick={login}>
            login
          </button>
        </div>
      )}
    </div>
  );
};

export default UserChallenge;
```

#### Project Structure - Default Export

/tutorial/04-project-structure/starter

There are more options

Normally somewhere in the src

/components/componentName.jsx
/screens/componentName.jsx

- create navbar folder

  - setup Navbar.jsx (component)
  - Navbar.css (styles)

- import in App.jsx

import Final from 'pathToFolder/Navbar/Navbar'

- first solution rename to index.jsx(entry point)

Works but eventually too many index tabs :):):)

- rename back to Navbar.jsx
- create index.jsx

```js
export { default } from "./Navbar";
```

#### Project Structure - Named Exports

/tutorial/04-project-structure/starter

- only makes sense if you have quite a few files

- create Pages directory
- setup two components Home.jsx and About.jsx

- import both in the App.jxs

import Home from 'pathToFolder/Pages/Home';
import About from 'pathToFolder/Pages/About';

A lot of work/lines of code

- create index.jsx

```js
import Home from "./Home";
import About from "./About";

export { Home, About };
```

in App.jsx

import {Home, About} from 'pathToFolder/Pages

#### Project Structure - Export Group

/tutorial/04-project-structure/starter

- create Example directory
- setup two components (setup simple returns) and index.jsx file
- in index.jsx setup return and render both components (import)
- import/render index.jsx in App.jsx

#### Project Structure - Extra Extensions

- code spell checker - works well with code and documents.
- glean - easy extract JSX into a new component

#### Leverage Javascript

[Javascript Nuggets -Optional Chaining](https://www.youtube.com/watch?v=PuEGrylM1x8&list=PLnHJACx3NwAfRUcuKaYhZ6T5NRIpzgNGJ&index=12&t=254s)

/tutorial/05-leverage-javascript/starter

Setup Challenge

- take a look at the people in array in data.js
- create List.jsx component
- in List.jsx import and iterate over people (data)
- for now just render name
- once you have list setup separate Person.jsx component
  - try glean extension
- in Person render
  - name, nickName, image

Yes, there will be a bug.

```js
import { people } from "../../../data";

const List = () => {
  return (
    <div>
      {people.map((person) => {
        return <div>{person.name}</div>;
      })}
    </div>
  );
};
export default List;
```

List.jsx

```js
import { people } from "../../../data";
import Person from "./Person";
const List = () => {
  return (
    <div>
      {people.map((person) => {
        return <Person key={person.name} {...person} />;
      })}
    </div>
  );
};
export default List;
```

Person.jsx

```js
import React from "react";
import avatar from "../../../assets/default-avatar.svg";

export function Person({ name, nickName = "shakeAndBake", images }) {
  // before optional chaining

  // const img =
  //   (images && images[0] && images[0].small && images[0].small.url) || avatar;
  // Combining with the nullish coalescing operator ??
  // const img = images?.[0]?.small?.url ?? avatar;
  // ?? vs || - please utilize the search engine

  const img = images?.[0]?.small?.url || avatar;

  return (
    <div>
      <img src={img} alt={name} style={{ width: "50px" }} />
      <h4>{name} </h4>
      <p>Nickname : {nickName}</p>
    </div>
  );
}
```

#### Default Values - Vanilla JS (Optional)

In JavaScript, when defining a function, you can specify default values for its parameters. This means that if a caller of the function does not provide a value for a particular parameter, the default value will be used instead. Default parameters are defined by assigning a value to the parameter in the function definition.

For example, consider the following function, which takes two parameters, x and y, and returns their sum:

```js
function add(x, y) {
  return x + y;
}
```

If we call this function with only one argument, it will return NaN because y is undefined.

We can set default values for x,y as:

```js
function add(x = 0, y = 0) {
  return x + y;
}
```

Now, if we call add(3), the function will return 3, because the default value of 0 is used for the y parameter.

#### Optional Chaining - Vanilla JS (Optional)

In JavaScript, the optional chaining operator (?.) is a new feature that allows you to access properties of an object without worrying about whether the object or the property is null or undefined. It's a shorthand for a common pattern of checking for null or undefined before accessing an object's property.

For example, consider the following code, which accesses the firstName property of an object:

```js
const person = { name: { first: "John", last: "Doe" } };
console.log(person.name.first);
```

If the name property is null or undefined, this code will throw an error. To prevent this, we can use the optional chaining operator:

```js
console.log(person?.name?.first);
```

Now, if the person.name is null or undefined, this code will simply return undefined instead of throwing an error. This make the code more robust and readable.

#### Controlled Inputs - Setup

```js
import Starter from "./tutorial/06-forms/starter/01-controlled-inputs.jsx";
```

Setup (for all form videos)

```js
const ControlledInputs = () => {
  return (
    <form className="form">
      <h4>controlled inputs</h4>
      <div className="form-row">
        <label htmlFor="name" className="form-label">
          name
        </label>
        <input type="text" className="form-input" id="name" />
      </div>
      <div className="form-row">
        <label htmlFor="email" className="form-label">
          Email
        </label>
        <input type="email" className="form-input" id="email" />
      </div>
      <button type="submit" className="btn btn-block">
        submit
      </button>
    </form>
  );
};
export default ControlledInputs;
```

#### Controlled Inputs - Complete

```js
import Starter from "./tutorial/06-forms/starter/01-controlled-inputs.jsx";
```

- setup state values
- add value and onChange to each input
- setup onSubmit

```js
import { useState } from "react";
const ControlledInputs = () => {
  const [name, setName] = useState("");
  const [email, setEmail] = useState("");

  // const handleChange = (e) => {
  //   // for now we won't use it
  //   const name = e.target.name;
  //   const value = e.target.value;
  // };

  const handleSubmit = (e) => {
    e.preventDefault();
    // do something
    console.log(name, email);
  };
  return (
    <form className="form" onSubmit={handleSubmit}>
      <h4>controlled inputs</h4>
      <div className="form-row">
        <label htmlFor="name" className="form-label">
          name
        </label>
        <input
          type="text"
          className="form-input"
          value={name}
          onChange={(e) => setName(e.target.value)}
          id="name"
        />
      </div>
      <div className="form-row">
        <label htmlFor="email" className="form-label">
          Email
        </label>
        <input
          type="email"
          className="form-input"
          id="email"
          value={email}
          onChange={(e) => setEmail(e.target.value)}
        />
      </div>
      <button type="submit" className="btn btn-block">
        submit
      </button>
    </form>
  );
};
export default ControlledInputs;
```

#### User Challenge

```js
import Starter from "./tutorial/06-forms/starter/02-user-challenge.jsx";
```

- setup controlled input (name input)
- setup onSubmit (for now just placeholder)
- import data array (first array) from data
- create another state value (data as default)
- iterate over and display right after form (h4)
- when user submits the form add new person to the list

- Extra Challenge
  - add button and setup functionality to remove user

```js
import { useState } from "react";
import { data } from "../../../data";
const UserChallenge = () => {
  const [name, setName] = useState("");
  const [users, setUsers] = useState(data);

  const handleSubmit = (e) => {
    e.preventDefault();
    // do something
    console.log(name);
    // if no value, do nothing
    if (!name) return;
    // if value, setup new user and add to current users
    const fakeId = Date.now();
    console.log(fakeId);
    // const newUser = { id: fakeId, name: name };
    const newUser = { id: fakeId, name };
    const updatedUsers = [...users, newUser];
    setUsers(updatedUsers);
    // set back to empty
    setName("");
  };

  const removeUser = (id) => {
    const updatedUsers = users.filter((person) => person.id !== id);
    setUsers(updatedUsers);
  };
  return (
    <div>
      <form className="form" onSubmit={handleSubmit}>
        <h4>Add User</h4>
        <div className="form-row">
          <label htmlFor="name" className="form-label">
            name
          </label>
          <input
            type="text"
            className="form-input"
            value={name}
            onChange={(e) => setName(e.target.value)}
            id="name"
          />
        </div>

        <button type="submit" className="btn btn-block">
          submit
        </button>
      </form>
      {/* render users */}
      <h2>users</h2>

      {users.map((user) => {
        return (
          <div key={user.id}>
            <h4>{user.name}</h4>
            <button onClick={() => removeUser(user.id)} className="btn">
              remove
            </button>
          </div>
        );
      })}
    </div>
  );
};
export default UserChallenge;
```

#### Multiple Inputs

```js
import Starter from "./tutorial/06-forms/starter/03-multiple-inputs.jsx";
```

[Javascript Nuggets - Dynamic Object Keys](https://www.youtube.com/watch?v=_qxCYtWm0tw&list=PLnHJACx3NwAfRUcuKaYhZ6T5NRIpzgNGJ&index=3&t=97s)

- inputs must have name attribute

```js
import { useState } from "react";
const MultipleInputs = () => {
  const [user, setUser] = useState({
    name: "",
    email: "",
    password: "",
  });

  const handleChange = (e) => {
    setUser({ ...user, [e.target.name]: e.target.value });
  };

  const handleSubmit = (e) => {
    e.preventDefault();
    console.log(user);
  };
  return (
    <div>
      <form className="form" onSubmit={handleSubmit}>
        <h4>Multiple Inputs</h4>
        {/* name */}
        <div className="form-row">
          <label htmlFor="name" className="form-label">
            name
          </label>
          <input
            type="text"
            className="form-input"
            id="name"
            name="name"
            value={user.name}
            onChange={handleChange}
          />
        </div>
        {/* email */}
        <div className="form-row">
          <label htmlFor="email" className="form-label">
            Email
          </label>
          <input
            type="email"
            className="form-input"
            id="email"
            name="email"
            value={user.email}
            onChange={handleChange}
          />
        </div>
        {/* password */}
        <div className="form-row">
          <label htmlFor="password" className="form-label">
            Password
          </label>
          <input
            type="password"
            className="form-input"
            id="password"
            name="password"
            value={user.password}
            onChange={handleChange}
          />
        </div>

        <button type="submit" className="btn btn-block">
          submit
        </button>
      </form>
    </div>
  );
};
export default MultipleInputs;
```

#### Other Inputs

```js
import Starter from "./tutorial/06-forms/starter/04-other-inputs.jsx";
```

```js
import { useState } from "react";
const frameworks = ["react", "angular", "vue", "svelte"];
const OtherInputs = () => {
  const [shipping, setShipping] = useState(false);
  const [framework, setFramework] = useState("react");

  const handleShipping = (e) => {
    console.log(e.target.checked);
    setShipping(e.target.checked);
  };
  const handleFramework = (e) => {
    setFramework(e.target.value);
  };
  return (
    <div>
      <form className="form">
        <h4>Other Inputs</h4>
        {/* name */}
        <div className="form-row" style={{ textAlign: "left" }}>
          <input
            type="checkbox"
            checked={shipping}
            id="shipping"
            name="shipping"
            onChange={handleShipping}
          />
          <label htmlFor="shipping"> Free Shipping </label>
        </div>
        <div className="form-row" style={{ textAlign: "left" }}>
          <label htmlFor="framework" className="form-label">
            Framework
          </label>
          <select
            name="framework"
            id="framework"
            value={framework}
            onChange={handleFramework}
          >
            {frameworks.map((framework) => {
              return <option key={framework}>{framework}</option>;
            })}
          </select>
        </div>
        <button type="submit" className="btn btn-block">
          submit
        </button>
      </form>
    </div>
  );
};
export default OtherInputs;
```

#### FormData API

```js
import Starter from "./tutorial/06-forms/starter/05-form-data.jsx";
```

[JS Nuggets - FormData API](https://youtu.be/5-x4OUM-SP8)

- a great solution when you have bunch of inputs
- inputs must have name attribute

The FormData interface provides a way to construct a set of key/value pairs representing form fields and their values, which can be sent using the fetch() or XMLHttpRequest.send() method. It uses the same format a form would use if the encoding type were set to "multipart/form-data".

```js
import { useState } from "react";

const UncontrolledInputs = () => {
  const [value, setValue] = useState(0);

  const handleSubmit = (e) => {
    e.preventDefault();

    const formData = new FormData(e.currentTarget);
    // const name = formData.get('name');
    // console.log(name);
    // console.log([...formData.entries()]);
    const newUser = Object.fromEntries(formData);
    // do something (post request, add to list, etc)
    console.log(newUser);
    // Gotcha - re-render won't clear out the values
    setValue(value + 1);
    // reset values
    e.currentTarget.reset();
  };
  return (
    <div>
      <form className="form" onSubmit={handleSubmit}>
        <h4>Form Data API</h4>
        {/* name */}
        <div className="form-row">
          <label htmlFor="name" className="form-label">
            name
          </label>
          <input type="text" className="form-input" id="name" name="name" />
        </div>
        {/* email */}
        <div className="form-row">
          <label htmlFor="email" className="form-label">
            Email
          </label>
          <input type="email" className="form-input" id="email" name="email" />
        </div>
        {/* password */}
        <div className="form-row">
          <label htmlFor="password" className="form-label">
            Password
          </label>
          <input
            type="password"
            className="form-input"
            id="password"
            name="password"
          />
        </div>

        <button type="submit" className="btn btn-block">
          submit
        </button>
      </form>
    </div>
  );
};
export default UncontrolledInputs;
```

- e.currentTarget

In React, e.currentTarget returns the DOM element that triggered the event.

- Object From Entries

The Object.fromEntries() static method transforms a list of key-value pairs into an object.

```js
const entries = new Map([
  ["foo", "bar"],
  ["baz", 42],
]);

const obj = Object.fromEntries(entries);

console.log(obj);
// Expected output: Object { foo: "bar", baz: 42 }
```

- reset()

The reset() method is a built-in method in HTML that can be used to reset all form controls to their initial values. When this method is called on a form element, it will clear any user-entered data and reset the values of all form elements to their default values.

#### useRef

```js
import Starter from "./tutorial/07-useRef/starter/01-useRef-basics.jsx";
```

- DOES NOT TRIGGER RE-RENDER
- preserves the value between renders
- target DOM nodes/elements
- When you want a component to “remember” some information, but you don’t want that information to trigger new renders, you can use a ref:

```js
import { useEffect, useRef, useState } from "react";

const UseRefBasics = () => {
  const [value, setValue] = useState(0);
  const refContainer = useRef(null);

  console.log(refContainer);
  // {current:null}
  // set value ourselves or DOM node

  useEffect(() => {
    // console.log(refContainer.current);
    refContainer.current.focus();
  });

  const isMounted = useRef(false);

  const handleSubmit = (e) => {
    e.preventDefault();
    console.log(refContainer.current);
    const name = refContainer.current.value;
    console.log(name);
  };

  useEffect(() => {
    if (!isMounted.current) {
      isMounted.current = true;
      return;
    }
    console.log("re-render");
  }, [value]);

  return (
    <div>
      <form className="form" onSubmit={handleSubmit}>
        <div className="form-row">
          <label htmlFor="name" className="form-label">
            Name
          </label>
          <input
            type="text"
            id="name"
            ref={refContainer}
            className="form-input"
          />
        </div>
        <button type="submit" className="btn btn-block">
          submit
        </button>
      </form>
      <h1>value : {value}</h1>
      <button onClick={() => setValue(value + 1)} className="btn">
        increase
      </button>
    </div>
  );
};

export default UseRefBasics;
```

#### Custom Hooks

```js
import Starter from "./tutorial/08-custom-hooks/starter/01-toggle.jsx";
```

- same rules as regular hooks
- simplify component (less code)
- re-use functionality

useToggle.js

```js
import { useState } from "react";

const useToggle = (defaultValue) => {
  const [show, setShow] = useState(defaultValue);
  const toggle = () => {
    setShow(!show);
  };
  return { show, toggle };
};

export default useToggle;
```

- Challenge

- in App.jsx import 02-fetch-data
- take a look at the component
- and try to setup custom fetch hook
- hint :
  hook should return isLoading,isError,user
  and take url as parameter

useFetchPerson.js

```js
import { useState, useEffect } from "react";

const useFetchPerson = (url) => {
  const [isLoading, setIsLoading] = useState(true);
  const [isError, setIsError] = useState(false);
  const [user, setUser] = useState(null);

  useEffect(() => {
    const fetchUser = async () => {
      try {
        const resp = await fetch(url);
        // console.log(resp);
        if (!resp.ok) {
          setIsError(true);
          setIsLoading(false);
          return;
        }

        const user = await resp.json();
        setUser(user);
      } catch (error) {
        setIsError(true);
        // console.log(error);
      }
      // hide loading
      setIsLoading(false);
    };
    fetchUser();
  }, []);

  return { isLoading, isError, user };
};

export default useFetchPerson;
```

Generic Fetch

useFetch.js

```js
import { useState, useEffect } from "react";

const useFetch = (url) => {
  const [isLoading, setIsLoading] = useState(true);
  const [isError, setIsError] = useState(false);
  // change state value
  const [data, setData] = useState(null);

  useEffect(() => {
    // change name
    const fetchData = async () => {
      try {
        const resp = await fetch(url);

        if (!resp.ok) {
          setIsError(true);
          setIsLoading(false);
          return;
        }
        // change to response
        const response = await resp.json();
        setData(response);
      } catch (error) {
        setIsError(true);
        // console.log(error);
      }
      // hide loading
      setIsLoading(false);
    };
    // invoke fetch data
    fetchData();
  }, []);

  return { isLoading, isError, data };
};

export default useFetch;
```

#### Context API

```js
import Starter from "./tutorial/09-context-api/starter";
```

Challenge

- create three components and nest them in such way :

- Navbar.jsx

  - NavLinks.jsx (nested in Navbar)
    - UserContainer.jsx (nested in NavLinks)

- import Navbar.jsx in App.jsx (remove container - CSS)
- in Navbar.jsx setup
  - user state value
    - default value {name:'something'}
  - logout function
    - set user back to null
- pass both of them down to UserContainer.jsx
- display user and button
- on button click set user back to null

- extra challenge
- if user null, in UserContainer display <p>please login</p>

Navbar.jsx

```js
import { useState } from "react";
import NavLinks from "./NavLinks";

const Navbar = () => {
  const [user, setUser] = useState({ name: "bob" });
  const logout = () => {
    setUser(null);
  };
  return (
    <nav className="navbar">
      <h5>CONTEXT API</h5>
      <NavLinks user={user} logout={logout} />
    </nav>
  );
};
export default Navbar;
```

NavLinks.jsx

```js
import UserContainer from "./UserContainer";

const NavLinks = ({ user, logout }) => {
  return (
    <div className="nav-container">
      <ul className="nav-links">
        <li>
          <a href="#">home</a>
        </li>
        <li>
          <a href="#">about</a>
        </li>
      </ul>
      <UserContainer user={user} logout={logout} />
    </div>
  );
};
export default NavLinks;
```

UserContainer.jsx

```js
const UserContainer = ({ user, logout }) => {
  return (
    <div className="user-container">
      {user ? (
        <>
          <p>Hello There, {user.name.toUpperCase()}</p>
          <button type="button" className="btn" onClick={logout}>
            logout
          </button>
        </>
      ) : (
        <p>Please Login</p>
      )}
    </div>
  );
};
export default UserContainer;
```

#### Setup Global Context

final code in the repo under w-assets

- create new VITE project

```sh
npm create vite@latest global-context -- --template react
```

- install and start the project

```sh
npm install && npm run dev
```

- in src create context.jsx
- setup a global context - GlobalContext
- setup a component (AppContext) with one state value
- return GlobalContext.Provider from AppContext
- wrap then entire application (main.jsx) - children prop "gotcha"
- setup a custom hook
- access in App.jsx
- log result

#### useReducer

```js
import Starter from "./tutorial/10-useReducer/starter/01-useReducer.jsx";
```

- it's the complete file from 03-useState-array

Challenge

- let's add reset functionality
- create function that set's people back to data array
- create another button, similar to clear just for reset
- use conditional rendering to toggle between the buttons,
  depending on people value

```jsx
function handleDeleteTask(taskId) {
  dispatch(
    // "action" object:
    {
      type: "deleted",
      id: taskId,
    }
  );
}
```

```js
const resetList = () => {
  setPeople(data);
};

// JSX
{
  people.length < 1 ? (
    <button className="btn" style={{ marginTop: "2rem" }} onClick={resetList}>
      reset
    </button>
  ) : (
    <button className="btn" style={{ marginTop: "2rem" }} onClick={clearList}>
      clear
    </button>
  );
}
```

```js
import React from "react";
import { data } from "../../../data";
const ReducerBasics = () => {
  const [people, setPeople] = React.useState(data);

  const removeItem = (id) => {
    let newPeople = people.filter((person) => person.id !== id);
    setPeople(newPeople);
  };
  const resetList = () => {
    setPeople(data);
  };
  return (
    <div>
      {people.map((person) => {
        const { id, name } = person;
        return (
          <div key={id} className="item">
            <h4>{name}</h4>
            <button onClick={() => removeItem(id)}>remove</button>
          </div>
        );
      })}
      {people.length < 1 ? (
        <button
          className="btn"
          style={{ marginTop: "2rem" }}
          onClick={resetList}
        >
          reset
        </button>
      ) : (
        <button
          className="btn"
          style={{ marginTop: "2rem" }}
          onClick={clearList}
        >
          clear
        </button>
      )}
    </div>
  );
};

export default ReducerBasics;
```

- A reducer function is where you will put your state logic. It takes two arguments, the current state and the action object, and it returns the next state:

#### Remove useState

```js
import { useState, useReducer } from "react";
import { data } from "../../../data";

// default/initial state
const defaultState = {
  people: data,
};
// reducer function
// whatever state is returned from the function is the new state

const reducer = (state, action) => {
  return state;
};

// dispatch({type:'SOME_ACTION'}) an action
// handle it in reducer, return new state

const ReducerBasics = () => {
  const [state, dispatch] = useReducer(reducer, defaultState);

  const removeItem = (id) => {
    // let newPeople = people.filter((person) => person.id !== id);
    // setPeople(newPeople);
  };

  const clearList = () => {
    // setPeople([]);
  };
  const resetList = () => {
    // setPeople(data);
  };

  return (
    <div>
      {/* switch to state */}
      {state.people.map((person) => {
        const { id, name } = person;
        return (
          <div key={id} className="item">
            <h4>{name}</h4>
            <button onClick={() => removeItem(id)}>remove</button>
          </div>
        );
      })}
      {/* switch to state */}
      {state.people.length < 1 ? (
        <button
          className="btn"
          style={{ marginTop: "2rem" }}
          onClick={resetList}
        >
          reset
        </button>
      ) : (
        <button
          className="btn"
          style={{ marginTop: "2rem" }}
          onClick={clearList}
        >
          clear
        </button>
      )}
    </div>
  );
};

export default ReducerBasics;
```

#### First Dispatch

```js
import { useState, useReducer } from "react";
import { data } from "../../../data";

const defaultState = {
  people: data,
  isLoading: false,
};

const reducer = (state, action) => {
  if (action.type === "CLEAR_LIST") {
    return { ...state, people: [] };
  }
};

const ReducerBasics = () => {
  const [state, dispatch] = useReducer(reducer, defaultState);

  const removeItem = (id) => {
    // let newPeople = people.filter((person) => person.id !== id);
    // setPeople(newPeople);
  };

  const clearList = () => {
    dispatch({ type: "CLEAR_LIST" });
    // setPeople([]);
  };
  const resetList = () => {
    // setPeople(data);
  };
  console.log(state);
  return (
    <div>
      {state.people.map((person) => {
        const { id, name } = person;
        return (
          <div key={id} className="item">
            <h4>{name}</h4>
            <button onClick={() => removeItem(id)}>remove</button>
          </div>
        );
      })}
      {state.people.length < 1 ? (
        <button
          className="btn"
          style={{ marginTop: "2rem" }}
          onClick={resetList}
        >
          reset
        </button>
      ) : (
        <button
          className="btn"
          style={{ marginTop: "2rem" }}
          onClick={clearList}
        >
          clear
        </button>
      )}
    </div>
  );
};

export default ReducerBasics;
```

#### Actions and Default State

```js
import { useReducer } from "react";
import { data } from "../../../data";

const CLEAR_LIST = "CLEAR_LIST";
const RESET_LIST = "RESET_LIST";
const REMOVE_ITEM = "REMOVE_ITEM";

const defaultState = {
  people: data,
};

const reducer = (state, action) => {
  console.log(action);
  if (action.type === CLEAR_LIST) {
    return { ...state, people: [] };
  }

  throw new Error(`No Matching "${action.type}" - action type`);
};

const ReducerBasics = () => {
  const [state, dispatch] = useReducer(reducer, defaultState);

  const removeItem = (id) => {};

  const clearList = () => {
    dispatch({ type: CLEAR_LIST });
  };

  const resetList = () => {};
  return (
    <div>
      {/* switch to state */}
      {state.people.map((person) => {
        const { id, name } = person;
        return (
          <div key={id} className="item">
            <h4>{name}</h4>
            <button onClick={() => removeItem(id)}>remove</button>
          </div>
        );
      })}
      {/* switch to state */}

      {state.people.length < 1 ? (
        <button
          className="btn"
          style={{ marginTop: "2rem" }}
          onClick={resetList}
        >
          reset
        </button>
      ) : (
        <button
          className="btn"
          style={{ marginTop: "2rem" }}
          onClick={clearList}
        >
          clear
        </button>
      )}
    </div>
  );
};

export default ReducerBasics;
```

```jsx
function tasksReducer(tasks, action) {
  switch (action.type) {
    case "added": {
      return [
        ...tasks,
        {
          id: action.id,
          text: action.text,
          done: false,
        },
      ];
    }
    case "changed": {
      return tasks.map((t) => {
        if (t.id === action.task.id) {
          return action.task;
        } else {
          return t;
        }
      });
    }
    case "deleted": {
      return tasks.filter((t) => t.id !== action.id);
    }
    default: {
      throw Error("Unknown action: " + action.type);
    }
  }
}
```

#### Reset List Challenge

- setup a dispatch and handle action in the reducer

```js
import { useReducer } from "react";
import { data } from "../../../data";

const CLEAR_LIST = "CLEAR_LIST";
const RESET_LIST = "RESET_LIST";
const REMOVE_ITEM = "REMOVE_ITEM";

const defaultState = {
  people: data,
};

const reducer = (state, action) => {
  console.log(action);
  if (action.type === CLEAR_LIST) {
    return { ...state, people: [] };
  }
  if (action.type === RESET_LIST) {
    return { ...state, people: data };
  }
  throw new Error(`No Matching "${action.type}" - action type`);
};

const ReducerBasics = () => {
  const [state, dispatch] = useReducer(reducer, defaultState);

  const removeItem = (id) => {};

  const clearList = () => {
    dispatch({ type: CLEAR_LIST });
  };
  const resetList = () => {
    dispatch({ type: RESET_LIST });
  };

  return (
    <div>
      {/* switch to state */}
      {state.people.map((person) => {
        const { id, name } = person;
        return (
          <div key={id} className="item">
            <h4>{name}</h4>
            <button onClick={() => removeItem(id)}>remove</button>
          </div>
        );
      })}
      {/* switch to state */}

      {state.people.length < 1 ? (
        <button
          className="btn"
          style={{ marginTop: "2rem" }}
          onClick={resetList}
        >
          reset
        </button>
      ) : (
        <button
          className="btn"
          style={{ marginTop: "2rem" }}
          onClick={clearList}
        >
          clear
        </button>
      )}
    </div>
  );
};

export default ReducerBasics;
```

#### Remove Person Challenge

- remove single person
- hint extra property in the object

```js
import { useReducer } from "react";
import { data } from "../../../data";

const CLEAR_LIST = "CLEAR_LIST";
const RESET_LIST = "RESET_LIST";
const REMOVE_ITEM = "REMOVE_ITEM";

const defaultState = {
  people: data,
};

const reducer = (state, action) => {
  console.log(action);
  if (action.type === CLEAR_LIST) {
    return { ...state, people: [] };
  }
  if (action.type === RESET_LIST) {
    return { ...state, people: data };
  }
  if (action.type === REMOVE_ITEM) {
    let newPeople = state.people.filter(
      (person) => person.id !== action.payload.id
    );

    return { ...state, people: newPeople };
  }

  return state;
};

const ReducerBasics = () => {
  const [state, dispatch] = useReducer(reducer, defaultState);

  const removeItem = (id) => {
    dispatch({ type: REMOVE_ITEM, payload: { id } });
  };

  const clearList = () => {
    dispatch({ type: CLEAR_LIST });
  };
  const resetList = () => {
    dispatch({ type: RESET_LIST });
  };

  return (
    <div>
      {/* switch to state */}
      {state.people.map((person) => {
        const { id, name } = person;
        return (
          <div key={id} className="item">
            <h4>{name}</h4>
            <button onClick={() => removeItem(id)}>remove</button>
          </div>
        );
      })}
      {/* switch to state */}

      {state.people.length < 1 ? (
        <button
          className="btn"
          style={{ marginTop: "2rem" }}
          onClick={resetList}
        >
          reset
        </button>
      ) : (
        <button
          className="btn"
          style={{ marginTop: "2rem" }}
          onClick={clearList}
        >
          clear
        </button>
      )}
    </div>
  );
};

export default ReducerBasics;
```

#### Import / Export

- create new file - actions.js

  - copy/paste all actions
  - export/import actions

- create new file - reducer.js

  - copy/paste reducer
  - import actions
  - import data
  - export/import reducer

#### UseContext

- Context lets the parent component make some information available to any component in the tree below it—no matter how deep—without passing it explicitly through props.

steps for using useContext

1. Create the context:

```jsx
import { createContext } from "react";

export const LevelContext = createContext(1);
```

2. useContext

```jsx
import { useContext } from "react";
import { LevelContext } from "./LevelContext.js";

export default function Heading({ children }) {
  const level = useContext(LevelContext);
  // ...
}
```

3. Provide Context

```jsx
import { LevelContext } from './LevelContext.js';

export default function Section({ level, children }) {
  return (
    <section className="section">
      <LevelContext.Provider value={level}>
        {children}
      </LevelContext.Provider>
    </section>
  );
}\

```

#### References values with ref

- When you want a component to “remember” some information, but you don’t want that information to trigger new renders, you can use a ref.

```jsx
const ref = useRef(0);
// useRef returns an object like this:
{
  current: 0; // The value you passed to useRef
}
```

- You can access the current value of that ref through the ref.current property. This value is intentionally mutable, meaning you can both read and write to it. It’s like a secret pocket of your component that React doesn’t track.

#### Manipulation the DOM with Refs

- React automatically updates the DOM to match your render output, so your components won’t often need to manipulate it. However, sometimes you might need access to the DOM elements managed by React—for example, to focus a node, scroll to it, or measure its size and position. There is no built-in way to do those things in React, so you will need a ref to the DOM node.
- <div ref={myRef}>

```jsx
import { useRef } from "react";

export default function Form() {
  const inputRef = useRef(null);

  function handleClick() {
    inputRef.current.focus();
  }

  return (
    <>
      <input ref={inputRef} />
      <button onClick={handleClick}>Focus the input</button>
    </>
  );
}
```

- if you want to reference to the react component then use as follows

```jsx
const MyInput = forwardRef((props, ref) => {
  return <input {...props} ref={ref} />;
});
```

#### Performance

#### Lower State / Push The State Down

```js
import Starter from "./tutorial/11-performance/starter/01-lower-state";
```

When Component Re-Renders :

- When the component's state or props change, React will re-render the component to reflect these changes.

- When the parent element re-renders, even if the component's state or props have not changed.

- lower state

```js
import { useState } from "react";
const Counter = () => {
  const [count, setCount] = useState(0);
  return (
    <button
      className="btn"
      onClick={() => setCount(count + 1)}
      style={{ marginBottom: "1rem" }}
    >
      count {count}
    </button>
  );
};
export default Counter;
```

#### Lower State Challenge

```js
import Starter from "./tutorial/11-performance/starter/02-lower-state-challenge";
```

- fix the re-rendering
- hint addPerson fix

```js
import { useState } from "react";

const Form = ({ addPerson }) => {
  const [name, setName] = useState("");
  const handleSubmit = (e) => {
    e.preventDefault();
    if (!name) {
      alert("Please Provide Name Value");
      return;
    }
    addPerson(name);
    setName("");
  };
  return (
    <form className="form" onSubmit={handleSubmit}>
      <div className="form-row">
        <label htmlFor="name" className="form-label">
          name
        </label>
        <input
          type="text"
          name="name"
          id="name"
          className="form-input"
          value={name}
          onChange={(e) => setName(e.target.value)}
        />
      </div>
      <button className="btn btn-block" type="submit">
        submit
      </button>
    </form>
  );
};
export default Form;
```

#### React.memo()

```js
import Starter from "./tutorial/11-performance/starter/03-hooks";
```

React.memo is a higher-order component (HOC) in React that allows you to memoize a component. This means that if the input props to the component have not changed, the memoized component will return the same result from the previous render, instead of re-rendering. This can help improve performance by avoiding unnecessary render cycles.

The React.memo function takes a functional component as its argument and returns a new component that has the same behavior, but with the added optimization of checking if the props have changed. If the props have not changed, the memoized component will return the cached result from the previous render.

Here's an example of using React.memo

```js
const MyComponent = React.memo(function MyComponent(props) {
  /* render logic */
});
```

React.memo(Component) - returns memoized component

#### Function "Gotcha"

- setup remove person function

```js
const removePerson = (id) => {
  const newPeople = people.filter((person) => person.id !== id);
  setPeople(newPeople);
};
```

- pass it down to List and Person

#### UseCallback

The useCallback hook is a hook in React that allows you to memoize a function. It takes two arguments: the first is the function you want to memoize, and the second is an array of dependencies. The hook will return a memoized version of the function that only changes if one of the values in the dependency array changes.

By memoizing the function, you can avoid unnecessary re-renders and improve the performance of your React application. The function will only be re-created if one of its dependencies changes, otherwise the same instance of the function will be returned. This can be useful in situations where you have an expensive function that you only want to recompute when its dependencies change.

Here is an example of how you might use useCallback:

```js
import React, { useCallback, useState } from "react";

function MyComponent() {
  const [data, setData] = useState([]);
  const handleClick = useCallback(() => {
    console.log(data);
  }, [data]);

  return (
    <div>
      <button onClick={handleClick}>Click me</button>
    </div>
  );
}
```

In this example, the handleClick function is memoized using useCallback and the data prop is passed as a dependency. This means that the handleClick function will only be re-created if the data prop changes.

#### useCallback - Common Use Case

```js
import Final from "./tutorial/02-useEffect/final/04-fetch-data";
```

```js
import { useState, useEffect, useCallback } from "react";
const url = "https://api.github.com/users";

const FetchData = () => {
  const [users, setUsers] = useState([]);
  const fetchData = useCallback(async () => {
    try {
      const response = await fetch(url);
      const users = await response.json();
      setUsers(users);
    } catch (error) {
      console.log(error);
    }
  }, []);

  useEffect(() => {
    fetchData();
  }, [fetchData]);
  // rest of the logic
};
```

#### useMemo

The useMemo hook is a hook in React that allows you to memoize a value. It takes two arguments: the first is a function that returns the value you want to memoize, and the second is an array of dependencies. The hook will return the memoized value that will only change if one of the values in the dependency array changes.

By memoizing a value, you can avoid unnecessary calculations and improve the performance of your React application. The value will only be recalculated if one of its dependencies changes, otherwise the same instance of the value will be returned. This can be useful in situations where you have an expensive calculation that you only want to recompute when its dependencies change.

Here is an example of how you might use useMemo:

```js
import React, { useMemo } from "react";

function MyComponent({ data }) {
  const processedData = useMemo(() => {
    return data.map((item) => item.toUpperCase());
  }, [data]);

  return (
    <div>
      {processedData.map((item) => (
        <div key={item}>{item}</div>
      ))}
    </div>
  );
}
```

In this example, the processedData value is memoized using useMemo and the data prop is passed as a dependency. This means that the processedData value will only be recalculated if the data prop changes.

- create slowFunction file
- setup a function
- import in index.js and set it equal to a value

```js
const slowFunction = () => {
  let value = 0;
  for (let i = 0; i <= 1000000000; i++) {
    value += i;
  }
  return value;
};

export default slowFunction;
```

#### useTransition

[JS Nuggets - Array.from](https://www.youtube.com/watch?v=zg1Bv4xubwo&list=PLnHJACx3NwAfRUcuKaYhZ6T5NRIpzgNGJ&index=11&t=666s)

```js
import Starter from "./tutorial/11-performance/starter/04-react-18";
```

- useTransition is a React Hook that lets you update the state without blocking the UI.

```js
import { useState, useTransition } from "react";
const LatestReact = () => {
  const [text, setText] = useState("");
  const [items, setItems] = useState([]);
  const [isPending, startTransition] = useTransition();

  const handleChange = (e) => {
    setText(e.target.value);

    startTransition(() => {
      const newItems = Array.from({ length: 5000 }, (_, index) => {
        return (
          <div key={index}>
            <img src="/vite.svg" alt="" />
          </div>
        );
      });
      setItems(newItems);
    });
  };
  return (
    <section>
      <form className="form">
        <input
          type="text"
          className="form-input"
          value={text}
          onChange={handleChange}
        />
      </form>
      <h4>Items Below</h4>
      {isPending ? (
        "Loading..."
      ) : (
        <div
          style={{
            display: "grid",
            gridTemplateColumns: "1fr 1fr 1fr",
            marginTop: "2rem",
          }}
        >
          {items}
        </div>
      )}
    </section>
  );
};
export default LatestReact;
```

#### Suspense API

The Suspense API is a feature in React that allows you to manage the loading state of your components. It provides a way to "suspend" rendering of a component until some data has been fetched, and display a fallback UI in the meantime. This makes it easier to handle asynchronous data loading and provide a smooth user experience in your React application.

Here is an example of how you might use the Suspense API:

```js
import React, { lazy, Suspense } from "react";

const DataComponent = lazy(() => import("./DataComponent"));

function MyComponent() {
  return (
    <Suspense fallback={<div>Loading...</div>}>
      <DataComponent />
    </Suspense>
  );
}
```

```js
import { useState, useTransition, lazy, Suspense } from "react";
const SlowComponent = lazy(() => import("./SlowComponent"));
const LatestReact = () => {
  const [text, setText] = useState("");
  const [items, setItems] = useState([]);
  const [isPending, startTransition] = useTransition();
  const [show, setShow] = useState(false);
  const handleChange = (e) => {
    setText(e.target.value);

    startTransition(() => {
      const newItems = Array.from({ length: 5000 }, (_, index) => {
        return (
          <div key={index}>
            <img src="/vite.svg" alt="" />
          </div>
        );
      });
      setItems(newItems);
    });
  };
  return (
    <section>
      <form className="form">
        <input
          type="text"
          className="form-input"
          value={text}
          onChange={handleChange}
        />
      </form>
      <h4>Items Below</h4>
      {isPending ? (
        "Loading..."
      ) : (
        <div
          style={{
            display: "grid",
            gridTemplateColumns: "1fr 1fr 1fr",
            marginTop: "2rem",
          }}
        >
          {items}
        </div>
      )}
      <button onClick={() => setShow(!show)} className="btn">
        toggle
      </button>
      {show && (
        <Suspense fallback={<h4>Loading...</h4>}>
          <SlowComponent />
        </Suspense>
      )}
    </section>
  );
};
export default LatestReact;
```

- typical setup (wrap entire return in Suspense)

```js
return (
  <Suspense fallback={<h4>Loading...</h4>}>
    {/* rest of the logic */}
    <section>{show && <SlowComponent />}</section>
  </Suspense>
);
```
