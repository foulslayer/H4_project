import mongoose from 'mongoose';
const { Schema, model } = mongoose;

const sensordataSchema = new Schema({
    afstand: String,
    time: String,
  }, { collection: 'Sensordata' });
  

const Sensordata = model('Sensordata', sensordataSchema);
export default Sensordata;