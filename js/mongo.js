import mongoose from 'mongoose';
//import Blog from '../model/Blog.js';
import express from 'express';
const app = express();
const PORT = 3000;

console.log('it was load')


mongoose.connect("mongodb+srv://kasperkammer:sRhTFEaDjgnAuq1b@cluster0.pno4poz.mongodb.net/afstandDB?retryWrites=true&w=majority")
  .then(() => {
    console.log('MongoDB connected successfully');
    app.listen(PORT, () => {
    // Define the server listening
   /* app.listen(PORT, () => {
      console.log(`Server is listening on port ${PORT}`);
      // Once the server is started, insert the article
      const article = new Blog({
        title: 'Awesome Post!',
        slug: 'awesome-post',
        published: true,
        content: 'This is the best post ever',
        tags: ['featured', 'announcement'],
      });
      article.save()
        .then(() => console.log('Article saved successfully'))
        .catch(err => console.error('Error saving article:', err));
    });*/


    try {
        const blogs = Blog.find();
        console.log('Found blogs:', blogs);
      } catch (err) {
        console.error('Error finding blogs:', err);
      }

  })}


  )
  .catch(err => console.error('Error connecting to MongoDB:', err));