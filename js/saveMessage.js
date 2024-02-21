import mongoose from 'mongoose';
import Sensordata from '../model/Sensordata.js';
import express from 'express';
/*const app = express();
const PORT = 3400;*/

console.log('it was load')



export const saveMessage =  async ({topic, message}) => {
    await mongoose.connect("mongodb+srv://kasperkammer:sRhTFEaDjgnAuq1b@cluster0.pno4poz.mongodb.net/afstandDB?retryWrites=true&w=majority")
    .then(() => {
      let date = new Date().toLocaleDateString();
      console.log('MongoDB connected successfully');
    
        const log = new Sensordata({
          afstand: message,
          time: date,
        });
        log.save()
          .then(() => console.log('Article saved successfully'))
          .catch(err => console.error('Error saving article:', err));
      });
    }

