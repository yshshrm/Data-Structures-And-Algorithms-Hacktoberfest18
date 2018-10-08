// phone number validator
export default function validatePhoneNumber(phone_number){
    if(phone_number != null){
        return phone_number.match(/^\d{10}$/);
    }
    return false;
}
